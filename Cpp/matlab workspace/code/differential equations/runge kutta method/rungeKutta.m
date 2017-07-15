%runge kutta method
%   takes in a function as a string - dy/dx = function, and
%   it's of the form f(x, y), an initial condition, a step size, and a
%   final x value

%following lines takes input from the user for the required parameters
func = input('enter the differential equation: dy/dx = ', 's');
x_initial = input('enter the initial x value: ');
y_initial = input('enter the initial y value: ');
step_size = input('enter the step size: ');
x_final = input('enter the final x value: ');

%initialize final y coordinate to current y
y_final = y_initial;

%initialize plot vectors
x = [];
y = [];

while x_initial + step_size < x_final
    vals = rungeKuttaFunctions(func, step_size, [x_initial y_final]);
    y_final = y_final + 1/6 * ...
              (vals(1) + 2 * vals(2) + 2 * vals(3) + vals(4));
    
    x = [x x_initial];
    y = [y, y_final];
    
    x_initial = x_initial + step_size;
        
end

fprintf('the final y value with an x value of %d is %d\n', x_final, y_final);
plot(x, y, 'bo');





