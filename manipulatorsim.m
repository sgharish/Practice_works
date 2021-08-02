 clc
clear
close all
%% DH- parameter of the manipulator is 

dh_parameter = [1 0 0 0; 1 0 0 0];

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
source = 'link1';
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


home = planar_arm.homeConfiguration;
%homef = planar_arm.homeConfiguration;
n = numel(home);
%% Linear path is selected to complete the application therefore the waypoint of the path are
% position of the end effector
waypointsmax =20;
waypoints = [0 1.5 0;... % start point 
0.25 1.5 0;
0.5 1.5 0;
0.75 1.5 0;
1 1.5 0;
1.25 1.5 0;
        1.5 1.5 0;
        1.75 1.5 0;
        1.75 1.5 0;
        1.75 1.25 0;
        1.75 1 0;
        1.75 1.5 0]';% end position 
numWaypoints = size(waypoints);
 %orientation(these values are selected randomly)   
orientation = [0 pi/2 0;...
    pi/2 pi/2 0;
    pi pi/2 0]';

% time for each waypoint
waytime = 0:2:22;

%% trajectory parameters

t = 0.2;
trajectoryT = 0:t:waytime(end);
tn = numel(trajectoryT);
%boundary conditions
waypointVels = 0.02 *[ 0  0.75  0;0.5 0 0;
                     0.75  0  0;
                     0.75  0  0;
                     0.75  0  0;
                      0.75 0.5 0 ;
                     0.75 0.75 0;
                      0.75 0.75 0;
                      0  0.75  0;
                      0 0.75 0;
                      0 0.75 0;
                      0.75 0.75 0]';
                  
% waypoint in space is 
plot3(waypoints(1,:),waypoints(2,:),waypoints(3,:),'x')

joint_ts = zeros(n,tn);

%% if joint angle is greater than or less than -pi then following is done
 home = jointAnglePosition';
 home(home > pi) = home(home > pi) - 2*pi;
 home(home < -pi) = home(home < -pi) + 2*pi;
% 
%% trajectory generation using cubic polynomial 
    
[q,qd,qdd] = cubicpolytraj(waypoints,waytime,trajectoryT, ... 
            'VelocityBoundaryCondition',waypointVels);
 
       
        %velo = [0.01; 0 ];
       
ik = inverseKinematics('RigidBodyTree',planar_arm);
weights = [0.5 0.5 0.5 1 1 1];
homeconfig = home;
%solve ik    
for idx = 1:tn
tgtPose = trvec2tform(q(:,idx)');
[configm,info] = ik(ee,tgtPose,weights,home);
home = configm;
joint_ts(:,idx) = configm;
eeTrans = getTransform(planar_arm,home,ee);
ee_pos(:,idx) = tform2trvec(eeTrans)';
error(:,idx) = q(:,idx)- ee_pos(:,idx);
end

%initial value for the ode
%intvelo = [0 0]; %velocity at the start is always zero
%solving ode using ode 15s
%[t,s] = ode15s(abs_loop(joint_ts,q,qd,qdd,tn,planar_arm,ee,trajectoryT,s),trajectroyT,[homeconfig;intvelo]);
plot3(q(1,:),q(2,:),q(3,:),'b-');

xlabel('X [m]');
ylabel('Y [m]');
zlabel('Z [m]');
legend('Task Space Trajectory');
% for idx = 1:n
%     figure, hold on;
%     plot(trajectoryT,joint_ts(idx,:),'b-');
%     for wIdx = 1:numWaypoints
%        xline(waytime(wIdx),'r-');
%     end
%     title(['Joint ' num2str(idx) ' Trajectory']);
%     xlabel('Time [s]');
%     ylabel('Joint Angle [rad]');
%     legend('Task Space Trajectory');
% end


% for idx = 1:tn
%     error(:,idx) = m_pos(:,idx) - q(:,idx);
% end

figure, hold on
plot(ee_pos(1,:),ee_pos(2,:),'g-');
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
H = massMatrix(planar_arm);

simQ = [trajectoryT;q];
%% planar arm detail and its skeleton is ///// using task space motion.
showdetails(planar_arm);



% 
% function ee_pos = abs_loop(joint_ts,q,qd,qdd,tn,planar_arm,ee,trajectoryT,s) 
% ik = inverseKinematics('RigidBodyTree',planar_arm);
% weights = [0.5 0.5 0.5 1 1 1];
% alpha =1;
% beta =1;
% eta =1;
% home = s[1];
% m_velo(:,1) = s[2]'; 
% eeTrans = getTransform(planar_arm,home,ee);
% m_pos(:,1) = tform2trvec(eeTrans)';
% for idx = 2:tn
%     jac = geometricJacobian(planar_arm,joint_ts(:,idx-1)','link2');%for the required position
%     J_g = jac(4:5,:);
%     % for the two link manipulator only the linear velocity representation of the Jacobian is taken into consideration
%     j_det = det(J_g);
%     inverse = (1/j_det)*J_g';
%     x_ddot = diff(q(:,idx-1));
%     error(:,idx-1) = m_pos(:,idx-1) - q(:,idx-1); %positional error
%     jac_tran = J_g';%transpose of the jacobian
%    
%     %subsystem z1 = error
%     %subsystem z1d = (J^{-1})*(xd -\alpha*z1); here xd is equal to the
%     %xddot in the paper.
%     
%     eie = x_ddot - (alpha*error(1:2,idx-1));  
%     eer_velo = inverse*eie; %subsystem1(virtual controller/velocity controller)
%     v_velo(:,idx) =  eer_velo';
%     dt = 0.3;
%     %c_vd = acc(i_vel,v_velo,dt);
%     yk = kinematic_Regressor_estimated(homeconfig,m_vel(idx-1,:),l,a); %kinematic regressor with estimated parameter
%     s = J_g*q(1:2,idx) - yk + alpha*error(1:2,idx-1);%required sliding vector(proof unknown)
%     
%     
%     z2 = qd(1:2,idx-1)- m_vel(idx-1,:)';%subsystem 2  
%     tgtPose = trvec2tform(m_pos(:,idx-1)');
%     [configm,info] = ik(ee,tgtPose,weights,homeconfig);
%     homecongfig = configm;
%     theta_ed = estimate_dynamic_parameter(homeconfig,a1,a2);
%     yd = dynamic_regressor(homeconfig,v_velo(:,idx)',qdd(1:2,idx-1)',l1,l2,a1,a2)*theta_ed;
%     torque(:,idx) = ( -(jac_tran*error(1:2,idx-1)) -(beta*jac_tran*s) - eta*(z2)+yd );%required torque
%     tor = torque(:,idx)';
%     
%     
%     %piece has to be changed currently to montior the position of the end
%     %effector
%     % to find the requried acceleration for the given torque forward
%     % dynamics is used.
%     m_acc(idx,:) = forwardDynamics(planar_arm,homeconfig,m_vel(idx-1,:),tor); 
%     m_vel(idx,:) = vel(m_acc(idx,:),dt,m_vel(idx-1,:));
%     homeconfig = configuration(m_acc(idx,:),m_vel(idx,:),homeconfig,dt);
%     
%     show(planar_arm,homeconfig,'Frames','on');
%     title(['Trajectory at t = ' num2str(trajectoryT(idx))]);
%     drawnow;
%     
%     eeTrans = getTransform(planar_arm,home,ee);
%     ee_pos = tform2trvec(eeTrans)';
%     m_pos = ee_pos;
% end     
% 
% 
% 
% %% required functions
% function yk = kinematic_Regressor_estimated(q,qd,l1,a2)
% theta_k = [l1;a2;l1;a2];%estimated error
% y_k = [-sin(q(:,1))*qd(:,1), -sin(q(:,1)+q(:,2))*(qd(:,1)+qd(:,2)),0,0;...
%     0,0,cos(q(:,1))*qd(:,1), cos(q(:,1)+q(:,2))*(qd(:,1)+qd(:,2))];
% yk = y_k*theta_k;
% end
% 
% %function to calculate the dynamic regressor of the system.
%  function yd = dynamic_regressor(q,qd,qdd,l1,l2,a1,a2)
%  g = 0; I1 = 0.6; I2 =0.2;m1 =0.5;m2= 0.52;
%  y11 = (l1^2)*qdd(:,1) + l1*g*cos(q(:,1));
%  y12 = 2*l1*qdd(:,1) +g*cos(q(:,1));
%  y13 = qdd(:,1);
%  y14 = 0;
%  y15 = ((l1^2)+2*l1*l2*cos(q(:,1))+(l2^2))*qdd(:,1) + (l1*l2*cos(q(:,2))+(l1^2))*qdd(:,2) - (2*l1*l2*sin(q(:,2))*qd(:,1)*qd(:,2))- l1*l2*sin(q(:,2))*(qd(:,2)^2) +l1*g*cos(q(:,1))+l2*g*cos(q(:,1)+q(:,2));
%  y16 = (2*l1*cos(q(:,1))+2*l2)*qdd(:,1) + (l1*cos(q(:,2))+2*l2)*qdd(:,2) - 2*l1*sin(q(:,1))*qd(:,1)*qd(:,2) - l1*sin(q(:,2))*(cos(q(:,2))^2)+g*cos(q(:,1)+q(:,2));
%  y17 = qdd(:,1)+qdd(:,2);
%  y18 = 0;
%  y21 =0; y22=0;y23=0;y24=0;y28=0;
%  y27 = qdd(:,1)+qdd(:,2);
%  y25 = (2*l1*l2*cos(q(:,2))+a2^2)*qdd(:,1)+ l2^2*qdd(:,2)+l1*l2*sin(q(:,2))*(qd(:,1))^2+l2*g*cos(q(:,1)+q(:,2));
%  y26 = (a1*cos(q(:,2))+2*l2)*qdd(:,1) + 2*l2*qdd(:,2) +l1*sin(q(:,2))*qd(:,1)^2+g*cos(q(:,1)+q(:,2));
%  yd = [y11,y12,y13,y14,y15,y16,y17,y18;...
%      y21,y22,y23,y24,y25,y26,y27,y28];
% 
% %  yd = y_d*phi;
%  end
% 
%  function theta_ed = estimate_dynamic_parameter(q,a1,a2)
%  m1=0.5;m2=0.52; I1 = 0.6;
%  p1 = m1;
%  p2 = m1*a1*cos(q(:,1));
%  p3 = I1+m1*a1*cos(q(:,1));
%  p4 = 0;
%  p5= m2;
%  p6 = m2*a2*cos(q(:,2));
%  p7= I1+m2*a2*cos(q(:,2));
%  p8= 0;
%   theta_ed = [p1,p2,p3,p4,p5,p6,p7,p8]'; 
%  end
% 
% %function to find the joint velocity. 
% function m_velo = vel(m_acc,dt,m_velo)
% m_velo = m_velo+(m_acc*dt);
% end
% 
% %function to find the configuration.
% function m_conf = configuration(a,v,s,t)
% m_conf = s+v*t+(1/2)*a*t;
% end
% 
% end


 


