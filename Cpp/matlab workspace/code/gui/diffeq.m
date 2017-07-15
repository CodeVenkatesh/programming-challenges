function varargout = diffeq(varargin)
% DIFFEQ MATLAB code for diffeq.fig
%      DIFFEQ, by itself, creates a new DIFFEQ or raises the existing
%      singleton*.
%
%      H = DIFFEQ returns the handle to a new DIFFEQ or the handle to
%      the existing singleton*.
%
%      DIFFEQ('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in DIFFEQ.M with the given input arguments.
%
%      DIFFEQ('Property','Value',...) creates a new DIFFEQ or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before diffeq_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to diffeq_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help diffeq

% Last Modified by GUIDE v2.5 04-Jun-2017 10:46:45

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @diffeq_OpeningFcn, ...
                   'gui_OutputFcn',  @diffeq_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before diffeq is made visible.
function diffeq_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to diffeq (see VARARGIN)

% Choose default command line output for diffeq
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes diffeq wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = diffeq_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on selection change in what_to_use.
function what_to_use_Callback(hObject, eventdata, handles)
% hObject    handle to what_to_use (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns what_to_use contents as cell array
%        contents{get(hObject,'Value')} returns selected item from what_to_use

contents = cellstr(get(handles.what_to_use, 'String'));

if contents{get(handles.what_to_use, 'Value')} == string('euler''s method')...
   || contents{get(handles.what_to_use, 'Value')} == string('runge kutta')
   
    set(handles.axes2, 'Visible', 'off');
    
    set(handles.a_static, 'Visible', 'off');
    set(handles.b_static, 'Visible', 'off');
    set(handles.c_static, 'Visible', 'off');
    set(handles.d_static, 'Visible', 'off');
    
    set(handles.a, 'Visible', 'off');
    set(handles.b, 'Visible', 'off');
    set(handles.c, 'Visible', 'off');
    set(handles.d, 'Visible', 'off');
    
    set(handles.time_start_static, 'Visible', 'off');
    set(handles.time_finish_static, 'Visible', 'off');
    set(handles.y0_x_static, 'Visible', 'off');
    set(handles.y0_y_static, 'Visible', 'off');
    
    set(handles.tstart, 'Visible', 'off');
    set(handles.tfinish, 'Visible', 'off');
    set(handles.y0_x, 'Visible', 'off');
    set(handles.y0_y, 'Visible', 'off');
    
elseif contents{get(handles.what_to_use, 'Value')} == ...
       string('predator prey')
   
    set(handles.func_static, 'Visible', 'off');
    set(handles.func, 'Visible', 'off');
        
    set(handles.x_init_static, 'Visible', 'off');
    set(handles.y_init_static, 'Visible', 'off');
    set(handles.step_size_static, 'Visible', 'off');
    set(handles.x_final_static, 'Visible', 'off');
       
    set(handles.x_init, 'Visible', 'off');
    set(handles.y_init, 'Visible', 'off');
    set(handles.step_size, 'Visible', 'off');
    set(handles.x_final, 'Visible', 'off');
    
end


% --- Executes during object creation, after setting all properties.
function what_to_use_CreateFcn(hObject, eventdata, handles)
% hObject    handle to what_to_use (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function func_Callback(hObject, eventdata, handles)
% hObject    handle to func (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of func as text
%        str2double(get(hObject,'String')) returns contents of func as a double


% --- Executes during object creation, after setting all properties.
function func_CreateFcn(hObject, eventdata, handles)
% hObject    handle to func (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function x_init_Callback(hObject, eventdata, handles)
% hObject    handle to x_init (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of x_init as text
%        str2double(get(hObject,'String')) returns contents of x_init as a double


% --- Executes during object creation, after setting all properties.
function x_init_CreateFcn(hObject, eventdata, handles)
% hObject    handle to x_init (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function y_init_Callback(hObject, eventdata, handles)
% hObject    handle to y_init (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of y_init as text
%        str2double(get(hObject,'String')) returns contents of y_init as a double


% --- Executes during object creation, after setting all properties.
function y_init_CreateFcn(hObject, eventdata, handles)
% hObject    handle to y_init (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function step_size_Callback(hObject, eventdata, handles)
% hObject    handle to step_size (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of step_size as text
%        str2double(get(hObject,'String')) returns contents of step_size as a double


% --- Executes during object creation, after setting all properties.
function step_size_CreateFcn(hObject, eventdata, handles)
% hObject    handle to step_size (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function x_final_Callback(hObject, eventdata, handles)
% hObject    handle to x_final (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of x_final as text
%        str2double(get(hObject,'String')) returns contents of x_final as a double


% --- Executes during object creation, after setting all properties.
function x_final_CreateFcn(hObject, eventdata, handles)
% hObject    handle to x_final (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function a_Callback(hObject, eventdata, handles)
% hObject    handle to a (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of a as text
%        str2double(get(hObject,'String')) returns contents of a as a double


% --- Executes during object creation, after setting all properties.
function a_CreateFcn(hObject, eventdata, handles)
% hObject    handle to a (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function b_Callback(hObject, eventdata, handles)
% hObject    handle to b (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of b as text
%        str2double(get(hObject,'String')) returns contents of b as a double


% --- Executes during object creation, after setting all properties.
function b_CreateFcn(hObject, eventdata, handles)
% hObject    handle to b (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function c_Callback(hObject, eventdata, handles)
% hObject    handle to c (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of c as text
%        str2double(get(hObject,'String')) returns contents of c as a double


% --- Executes during object creation, after setting all properties.
function c_CreateFcn(hObject, eventdata, handles)
% hObject    handle to c (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function d_Callback(hObject, eventdata, handles)
% hObject    handle to d (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of d as text
%        str2double(get(hObject,'String')) returns contents of d as a double


% --- Executes during object creation, after setting all properties.
function d_CreateFcn(hObject, eventdata, handles)
% hObject    handle to d (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function tstart_Callback(hObject, eventdata, handles)
% hObject    handle to tstart (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of tstart as text
%        str2double(get(hObject,'String')) returns contents of tstart as a double


% --- Executes during object creation, after setting all properties.
function tstart_CreateFcn(hObject, eventdata, handles)
% hObject    handle to tstart (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function tfinish_Callback(hObject, eventdata, handles)
% hObject    handle to tfinish (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of tfinish as text
%        str2double(get(hObject,'String')) returns contents of tfinish as a double


% --- Executes during object creation, after setting all properties.
function tfinish_CreateFcn(hObject, eventdata, handles)
% hObject    handle to tfinish (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function y0_x_Callback(hObject, eventdata, handles)
% hObject    handle to y0_x (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of y0_x as text
%        str2double(get(hObject,'String')) returns contents of y0_x as a double


% --- Executes during object creation, after setting all properties.
function y0_x_CreateFcn(hObject, eventdata, handles)
% hObject    handle to y0_x (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function y0_y_Callback(hObject, eventdata, handles)
% hObject    handle to y0_y (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of y0_y as text
%        str2double(get(hObject,'String')) returns contents of y0_y as a double


% --- Executes during object creation, after setting all properties.
function y0_y_CreateFcn(hObject, eventdata, handles)
% hObject    handle to y0_y (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in plot.
function plot_Callback(hObject, eventdata, handles)
% hObject    handle to plot (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

contents = cellstr(get(handles.what_to_use, 'String'));

if contents{get(handles.what_to_use, 'Value')} == string('euler''s method')
    funct = strcat(string('dy/dx = '), get(handles.func, 'String'));
    
    [x, y] = euler(funct, str2double(get(handles.x_init, 'String')), ...
                         str2double(get(handles.y_init, 'String')), ...
                         str2double(get(handles.step_size, 'String')), ...
                         str2double(get(handles.x_final, 'String')));
    
    plot(handles.axes1, x, y);
    set(handles.axes1, 'XMinorTick', 'on');
    
elseif contents{get(handles.what_to_use, 'Value')} == ...
       string('runge kutta')
   
   [x, y] = RK4(get(handles.func, 'String'), ...
               str2double(get(handles.x_init, 'String')), ...
               str2double(get(handles.y_init, 'String')), ...
               str2double(get(handles.step_size, 'String')), ...
               str2double(get(handles.x_final, 'String')));
           
    plot(handles.axes1, x, y);
    set(handles.axes1, 'XMinorTick', 'on');
    
elseif contents{get(handles.what_to_use, 'Value')} == ...
       string('predator prey')
   
   tspan = [str2double(get(handles.tstart, 'String')), ...
            str2double(get(handles.tfinish, 'String'))];
   y0 = [str2double(get(handles.y0_x, 'String')), ...
         str2double(get(handles.y0_y, 'String'))];
   
   [t, y] = pred_prey(str2double(get(handles.a, 'String')), ...
                      str2double(get(handles.b, 'String')), ...
                      str2double(get(handles.c, 'String')), ...
                      str2double(get(handles.d, 'String')), tspan, y0);
                  
    plot(handles.axes1, t, y(:, 1), 'b.-', t, y(:, 2), 'k.-');
    set(handles.axes1, 'XMinorTick', 'on');
    
    plot(handles.axes2, y(:, 1), y(:, 2), 'b.-');
    set(handles.axes2, 'XMinorTick', 'on');                         
end

set(handles.axes2, 'Visible', 'on');

set(handles.a_static, 'Visible', 'on');
set(handles.b_static, 'Visible', 'on');
set(handles.c_static, 'Visible', 'on');
set(handles.d_static, 'Visible', 'on');

set(handles.a, 'Visible', 'on');
set(handles.b, 'Visible', 'on');
set(handles.c, 'Visible', 'on');
set(handles.d, 'Visible', 'on');

set(handles.time_start_static, 'Visible', 'on');
set(handles.time_finish_static, 'Visible', 'on');
set(handles.y0_x_static, 'Visible', 'on');
set(handles.y0_y_static, 'Visible', 'on');

set(handles.tstart, 'Visible', 'on');
set(handles.tfinish, 'Visible', 'on');
set(handles.y0_x, 'Visible', 'on');
set(handles.y0_y, 'Visible', 'on');

set(handles.func_static, 'Visible', 'on');
set(handles.func, 'Visible', 'on');

set(handles.x_init_static, 'Visible', 'on');
set(handles.y_init_static, 'Visible', 'on');
set(handles.step_size_static, 'Visible', 'on');
set(handles.x_final_static, 'Visible', 'on');

set(handles.x_init, 'Visible', 'on');
set(handles.y_init, 'Visible', 'on');
set(handles.step_size, 'Visible', 'on');
set(handles.x_final, 'Visible', 'on');

pause(3)

if contents{get(handles.what_to_use, 'Value')} == string('predator prey')
    plot(handles.axes2, y(:, 1), y(:, 2), 'w.-');
end
