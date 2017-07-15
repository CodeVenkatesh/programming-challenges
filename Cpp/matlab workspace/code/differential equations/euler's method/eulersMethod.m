%given a differential equation, an initial condition, the step size, and
%the final point to end at, approximate the y value of the final point
%assume diff_eq is of the form dy/dx = x/k + y/j for simplicity

%five lines below get inputs
diff_eq = input('enter the differential equation: ', 's');
x_initial = input('enter the initial x value: ');
y_initial = input('enter the initial y value: ');
step_size = input('enter the step size: ');
x_final = input('enter the final x point: ');

%initialize final y value to 0
y_final = 0;

%two lines below split diff eq string into ["dy/dx", "x/k", "+/-", "y/j"]
tokens = split(string(diff_eq), ' ');
tokens(2) = [];

%copy initial x value - check for whether or not first time in process
copy = x_initial;

%the equation of the tangent line - initialized to empty string 
equation = '';

%vectors for plotting
x = [];
y = [];

while(copy <= x_final + step_size)
    if copy == x_initial
        m = ...
            calcSlope([x_initial, y_initial], tokens(2), tokens(3), ...
                      tokens(4));
        
        equation = strcat(string('y-'), string(y_initial));
        equation = strcat(equation, string(' = '));
        equation = strcat(equation, string(m));
        equation = strcat(equation, string(' (x-'));
        equation = strcat(equation, string(x_initial));
        equation = strcat(equation, string(')'));
        
        %initialize x and y
        x = [x x_initial];
        y = [y y_initial];
        
    else
        split_equation = split(equation, ' ');
        y_final = evalEquation(copy, split_equation);
        m = calcSlope([copy, y_final], tokens(2), tokens(3), tokens(4));
        equation = strcat(string('y-'), string(y_final));
        equation = strcat(equation, string(' = '));
        equation = strcat(equation, string(m));
        equation = strcat(equation, string(' (x-'));
        equation = strcat(equation, string(copy));
        equation = strcat(equation, string(')'));
        
        %fill with points
        x = [x copy];
        y = [y y_final];
    end
    
    copy = copy + step_size;
        
end

fprintf('the final y value at x = %d is %d\n', x_final, y_final);
plot(x, y, 'bo');