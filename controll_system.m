% checking the controllability of the system
%based on few exercise available in the internet this is been tried
A = [-1  0;0 -1]
B = [1;5]
% question to chewck the controlability of the system
cont = ctrb(A,B)
ran = rank(cont)
% system is uncontrollable
%to determine the uncontrollable states of the system following is
%performed
uncont = length(A) - ran
%it has one uncontrollable state

%observability
C=[1 5]
obser = obsv(A,C)
rann = rank(obser)
%system is not observable

% designing A feedback for the controllable system 3x3

A3 = [1 2 3;0 1 1;1 0 2]
B3 = [1;3;4]
cont3 = ctrb(A3,B3)
ran3 = rank(cont3)

