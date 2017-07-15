function outarg = calcSlope( point, str_x, str_sign, str_y )
%given a differential equation and a point, calculate the slope
%   essentially evaluates dy/dx given a point, though for simplicity, dy/dx
%   is considered to be of the form x/k + y/j

split_x = split(str_x, '/');
eval_x = point(1)/(str2double(split_x(2)));

split_y = split(str_y, '/');
eval_y = point(2)/(str2double(split_y(2)));

if str_sign == '+'
    outarg = eval_x + eval_y;    
else
    outarg = eval_x - eval_y;    
end

end

