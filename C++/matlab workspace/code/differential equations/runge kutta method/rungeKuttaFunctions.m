function outarg = rungeKuttaFunctions( func, step_size, point )
%determines the four needed values for the runge kutta method
%   given a function, the step size, and the point to plug in, F1, F2, F3,
%   and F4 are evaluated (which then produce the iterated y coordinate)

if contains(func, 'e^')
    func = replace(func, 'e', num2str(exp(1), 12));
elseif contains(func, 'pi')
    func = replace(func, 'pi', num2str(pi, 12));
end

func = strcat(string(step_size), string('*'), func);

%determine first part of runge kutta method
F1 = replace(func, 'x', num2str(point(1)));
F1 = replace(F1, 'y', num2str(point(2)));
F1 = eval(char(F1));

%determine second part of runge kutta method
new_x = point(1) + step_size/2;
new_y = point(2) + F1/2;
F2 = replace(func, 'x', num2str(new_x));
F2 = replace(F2, 'y', num2str(new_y));
F2 = eval(char(F2));

%determine third part of runge kutta method
new_y = point(2) + F2/2;
F3 = replace(func, 'x', num2str(new_x));
F3 = replace(F3, 'y', num2str(new_y));
F3 = eval(char(F3));

%determine fourth part of runge kutta method
new_x = point(1) + step_size;
new_y = point(2) + F3;
F4 = replace(func, 'x', num2str(new_x));
F4 = replace(F4, 'y', num2str(new_y));
F4 = eval(char(F4));

outarg = [F1 F2 F3 F4];

end

