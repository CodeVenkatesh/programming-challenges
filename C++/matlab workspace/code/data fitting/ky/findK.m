function k = findK( xdata, ydata, y0 )
%UNTITLED15 Summary of this function goes here
%   Detailed explanation goes here

F = @(r) r(1) .* exp(xdata .* r(2)) - ydata;
x0 = [rand, y0 + rand];

options = optimoptions(@lsqnonlin,'Algorithm','trust-region-reflective');
k = lsqnonlin(F, x0, [], [], options);


times = linspace(xdata(1), xdata(end));

plot(xdata, ydata, 'ko', times, k(1) * exp(times * k(2)), 'b-');


end

