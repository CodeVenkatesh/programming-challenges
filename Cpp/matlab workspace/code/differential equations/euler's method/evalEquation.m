function outarg = evalEquation( x_val, equation )
%evaluates an equation given an x value 
%   solves for y given x, expects the equation to be in point slope form

%currently, equation should look like ["y-b", "=", "m", "(x - c)"]
%following 2 lines extracts the "b" value
split_y = split(equation(1), '-');
b = str2double(split_y(2));

%remove the parentheses from "(x - c)"
x_without_paren = extractBetween(equation(4), '(', ')');

%following 2 lines extracts the "c" value
split_x = split(x_without_paren, '-');
c = str2double(split_x(2));

%change slope to double
m = str2double(equation(3));

outarg = b + m * (x_val - c);

end

