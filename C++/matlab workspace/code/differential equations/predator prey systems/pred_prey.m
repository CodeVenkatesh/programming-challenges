function [t, y] = pred_prey( a, b, c, d, tspan, y0 )
%predator prey model
%   functions:
%       prey = a * prey - b * prey * pred
%       pred = -c * pred + d * prey * pred
%   both tspan and y0 are vectors, a, b, c, d numbers

F = @(t,y) [a * y(1) - b * y(1) .* y(2); 
            d * y(1) .* y(2) - c * y(2)];

[t, y] = ode45(F, tspan, y0);

end

