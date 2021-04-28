 clc
close all
%% DH- parameter of the manipulator is 

dh_parameter = [1 0 0 0; 1.5 0 0 0];

%% Planar arm under study skeleton is 
planar_arm = rigidBodyTree('DataFormat','row');

%% link1 of the arm is
link_1 = rigidBody('base1');
rb_joint = rigidBodyJoint('joint1','revolute');
setFixedTransform(rb_joint,dh_parameter(1,:),"dh");
link_1.Joint = rb_joint;
addBody(planar_arm,link_1,'base');

%% link 2 of the arm is
link_2 = rigidBody('link1');
r_joint = rigidBodyJoint('joint2','revolute');
setFixedTransform(r_joint,dh_parameter(2,:),"dh");
link_2.Joint = r_joint;
addBody(planar_arm,link_2,'base1');
link_3 = rigidBody('link2');
addBody(planar_arm,link_3,'link1');

ee = 'link2';

jointAnglePosition = [pi;pi];
jointAngleRetract = [pi;pi];

%% path and trajectory definition
%% waypoints for the manipulator. In this the straight line is consider as the path therefore the waypoints are
interact = interactiveRigidBodyTree(planar_arm);
ax = gca;
plane = collisionBox(1,0,1);
plane.Pose = trvec2tform([0 -0.025 0 ]);
show(plane,'Parent', ax);

%% for configuration of the manipulator arm in the space
interact.MarkerBodyName = "link2";
%% but in this case the arm is placed in the homeconfiguration in initial condition


randConfig = planar_arm.randomConfiguration;
% tranfromation of end effector w.r.t base
tform = getTransform(planar_arm,randConfig,'link2','base');

ik = inverseKinematics('RigidBodyTree',planar_arm);
weights = [0.5 0.5 0.5 1 1 1];
home = planar_arm.homeConfiguration;
n = numel(home);
%% Linear path is selected to complete the application therefore the waypoint of the path are
% position of the end effector
waypointsmax =20;
waypoints = [0 1.5 0;... % start point 
        1 1.5 0;
        1.5 1.5 0;
        2 1.5 0;
        2 1 0;
        2 1.5 0]';% end position 
numWaypoints = size(waypoints);
 %orientation(these values are selected randomly)   
orientation = [0 pi/2 0;...
    pi/2 pi/2 0;
    pi pi/2 0]';

% time for each waypoint
waytime = 0:0.4:2;

%% trajectory parameters

t = 0.3;
trajectoryT = 0:t:waytime(end);
tn = numel(trajectoryT);
%boundary conditions
waypointVels = 0.01 *[ 0  1  0;
                     1  0  0;
                     1 1 0;
                      0  1  0;
                      0 1 0;
                      1 1 0]';
                  
% waypoint in space is 
plot3(waypoints(1,:),waypoints(2,:),waypoints(3,:),'x')

joint_ts = zeros(n,tn);

%% if joint angle is greater than or less than -pi then following is done
 home = jointAnglePosition';
 home(home > pi) = home(home > pi) - 2*pi;
 home(home < -pi) = home(home < -pi) + 2*pi;
% 
%% trajectory generation using cubic polynomial 
%[q,qd,qdd] = cubicpolytraj(waypoints,waytime,trajectoryT,waypointVels);
[q,qd,qdd] = cubicpolytraj(waypoints,waytime,trajectoryT, ... 
            'VelocityBoundaryCondition',waypointVels);
   alpha = 100;
   beta =100;
   eta = 50;
   while i < tn+1
       i = i+1;
   end
for idx = 1:tn
    xdd(:,idx) = diff(q(:,idx));
    
end
    velo = [0.01; 0.01 ];
%     tgtPose = trvec2tform(q(:,1)');
%    [configm,info] = ik(ee,tgtPose,weights,home);
%    home = configm;
% %     
%     joint_ts(:,1) = configm;
%     jac = geometricJacobian(planar_arm,configm,'link2');%for the required position
%     ij = inv(jac(3:4,:));
%     veloc = ij*velo;
%       xd = jac(3:4,:)*veloc;
%      eeTrans = getTransform(planar_arm,configm,ee);
%      ee_pos(:,1) = tform2trvec(eeTrans);
%      error = ee_pos(:,idx) - q(:,idx);
%      jac_tran = jac(3:4,:)';
%      eie = xd - (alpha*error);
%      eer_velo = ij*eie;
%      s = jac(3:4,:)*q(1:2,1) - xd + alpha*error;
%      z2 = veloc(1:2,:) - qd(1:2,1);
%      torque = - (jac_tran*error) - (beta*jac_tran*s) - eta*(z2);
    
for idx = 1:tn
    % Solve IK
     tgtPose = trvec2tform(q(:,idx)');
    [configm,info] = ik(ee,tgtPose,weights,home);
    home = configm;
    
    joint_ts(:,idx) = configm;
    eeTrans = getTransform(planar_arm,configm,ee);
    ee_pos(:,idx) = tform2trvec(eeTrans)';
end
m_pos =  ee_pos(:,1);
m_vel = [0,0];
    
%         %jac_n = geometricJacobian(planar_arm,,'link2');
%     %ij_n = inv(jac_n(3:4,:));
%     %dlin_velo = jac(3:4,:)*qd(1:2,idx);
%     %ee_qd(:,idx) = ij_n*velo;
conf = joint_ts(:,1)';
for idx = 1:tn
jac = geometricJacobian(planar_arm,conf,'link2');%for the required position
    ij = inv(jac(4:5,:));
    veloc = ij*velo;
    xd = jac(3:4,:)*veloc;     
    error(:,idx) = m_pos(1:2,:) - q(1:2,idx);
    jac_tran = jac(3:4,:)';
    eie = xd - (alpha*error(:,idx));
    eer_velo = ij*eie;
    s = jac(3:4,:)*q(1:2,idx) - xd + alpha*error(:,idx);
    z2 = m_vel' - qd(1:2,idx);
    torque = ( -(jac_tran*error(:,idx)) - (beta*jac_tran*s) - eta*(z2));
    show(planar_arm,conf,'Frames','on');
    title(['Trajectory at t = ' num2str(trajectoryT(idx))]);
    drawnow;
    m_acc = forwardDynamics(planar_arm,joint_ts(:,idx)',m_vel,torque');
    dt = 0.3;
    m_vel = cumtrapz(dt,m_acc);
    conf = cumtrapz(dt,m_vel);
    eeTrans = getTransform(planar_arm,conf,ee);
    m_pos = tform2trvec(eeTrans)';
    eem_pos(:,idx) = tform2trvec(eeTrans)';
end     
%     jac_tran = jac(3:4,:)';
%     eie = xd - (alpha*error(1:2,idx));
%     eer_velo = ij*eie;
%     s = jac(3:4,:)*q(1:2,idx) - xd + alpha*error(1:2,idx);
%     z2 = m_vel - qd(1:2,idx);
%     torque(:,idx) = - (jac_tran*error(1:2,idx)) - (beta*jac_tran*s) - eta*(z2);
%     
% for idx = 1:tn    
%     show(planar_arm,configm,'Frames','on');
%     title(['Trajectory at t = ' num2str(trajectoryT(idx))]);
%     drawnow;
% end

plot3(q(1,:),q(2,:),q(3,:),'b-');

xlabel('X [m]');
ylabel('Y [m]');
zlabel('Z [m]');
legend('Task Space Trajectory');
for idx = 1:n
    figure, hold on;
    plot(trajectoryT,joint_ts(idx,:),'b-');
    for wIdx = 1:numWaypoints
       xline(waytime(wIdx),'r-');
    end
    title(['Joint ' num2str(idx) ' Trajectory']);
    xlabel('Time [s]');
    ylabel('Joint Angle [rad]');
    legend('Task Space Trajectory');
end


% for idx = 1:tn
%     error(:,idx) = m_pos(:,idx) - q(:,idx);
% end

figure, hold on
plot(eem_pos(1,:),eem_pos(2,:),'g-');
plot3(q(1,:),q(2,:),q(3,:),'b-');
plot3(waypoints(1,:),waypoints(2,:),waypoints(3,:),'ko','LineWidth',2);
title('Waypoints, Trajectory position, End effector positions')
xlabel('X [m]');
ylabel('Y [m]');
legend('End effector position','Desired position','Waypoints');

figure, hold off
plot(error(1,:),error(2,:),'r--');
title('Position Error')
xlabel('X [m]');
ylabel('Y [m]');
legend('Error');
 velo = [0.01 0.01 ]';
H = massMatrix(planar_arm);
%% planar arm detail and its skeleton is
% tspan = linspace(0,5,25);
% motionModel = taskSpaceMotionModel("RigidBodyTree",planar_arm,'EndEffectorName','link2');
% % [t,state] = ode15s(@(t,state)derivative(motionModel,state,q(:,1)',qd(:,1)'),trajectoryT,[home;zeros(3,1)]);
% %  plot(t,state);
% motionModel.Kp(1:6,1:6) = 0;
% motionModel.Kd(1:6,1:6) = 0;
% refpos = q(1:2,1)'
% refvel = qd(1:2,1)'
% [t,state] = ode15s(@(t,state)derivative(motionModel,state,refpos,refvel),trajectoryT,[home;zeros(3,1)])

  
showdetails(planar_arm);






