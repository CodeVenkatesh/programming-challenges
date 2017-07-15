function [xdata, ydata, initpoint] = getDataK( k, tspan, y0 )
%UNTITLED14 Summary of this function goes here
%   Detailed explanation goes here

F = @(t,y) k * y;

[t, y] = ode45(F, tspan, y0);

%plot(t, y, 'b-');

noise = randn(length(t), 1);

xdata = t;
ydata = y + noise;
initpoint = y0;

%plot(xdata, ydata, 'k-');

end

