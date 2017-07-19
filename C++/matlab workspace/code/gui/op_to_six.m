function varargout = op_to_six(varargin)
% OP_TO_SIX MATLAB code for op_to_six.fig
%      OP_TO_SIX, by itself, creates a new OP_TO_SIX or raises the existing
%      singleton*.
%
%      H = OP_TO_SIX returns the handle to a new OP_TO_SIX or the handle to
%      the existing singleton*.
%
%      OP_TO_SIX('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in OP_TO_SIX.M with the given input arguments.
%
%      OP_TO_SIX('Property','Value',...) creates a new OP_TO_SIX or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before op_to_six_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to op_to_six_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help op_to_six

% Last Modified by GUIDE v2.5 27-May-2017 05:56:42

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @op_to_six_OpeningFcn, ...
                   'gui_OutputFcn',  @op_to_six_OutputFcn, ...
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


% --- Executes just before op_to_six is made visible.
function op_to_six_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to op_to_six (see VARARGIN)

% Choose default command line output for op_to_six
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes op_to_six wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = op_to_six_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;



function num1_Callback(hObject, eventdata, handles)
% hObject    handle to num1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of num1 as text
%        str2double(get(hObject,'String')) returns contents of num1 as a double


% --- Executes during object creation, after setting all properties.
function num1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to num1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function num2_Callback(hObject, eventdata, handles)
% hObject    handle to num2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of num2 as text
%        str2double(get(hObject,'String')) returns contents of num2 as a double


% --- Executes during object creation, after setting all properties.
function num2_CreateFcn(hObject, eventdata, handles)
% hObject    handle to num2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function num3_Callback(hObject, eventdata, handles)
% hObject    handle to num3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of num3 as text
%        str2double(get(hObject,'String')) returns contents of num3 as a double


% --- Executes during object creation, after setting all properties.
function num3_CreateFcn(hObject, eventdata, handles)
% hObject    handle to num3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function num4_Callback(hObject, eventdata, handles)
% hObject    handle to num4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of num4 as text
%        str2double(get(hObject,'String')) returns contents of num4 as a double


% --- Executes during object creation, after setting all properties.
function num4_CreateFcn(hObject, eventdata, handles)
% hObject    handle to num4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function num6_Callback(hObject, eventdata, handles)
% hObject    handle to num6 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of num6 as text
%        str2double(get(hObject,'String')) returns contents of num6 as a double


% --- Executes during object creation, after setting all properties.
function num6_CreateFcn(hObject, eventdata, handles)
% hObject    handle to num6 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function num5_Callback(hObject, eventdata, handles)
% hObject    handle to num5 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of num5 as text
%        str2double(get(hObject,'String')) returns contents of num5 as a double


% --- Executes during object creation, after setting all properties.
function num5_CreateFcn(hObject, eventdata, handles)
% hObject    handle to num5 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in sign1.
function sign1_Callback(hObject, eventdata, handles)
% hObject    handle to sign1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns sign1 contents as cell array
%        contents{get(hObject,'Value')} returns selected item from sign1


% --- Executes during object creation, after setting all properties.
function sign1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to sign1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in sign2.
function sign2_Callback(hObject, eventdata, handles)
% hObject    handle to sign2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns sign2 contents as cell array
%        contents{get(hObject,'Value')} returns selected item from sign2


% --- Executes during object creation, after setting all properties.
function sign2_CreateFcn(hObject, eventdata, handles)
% hObject    handle to sign2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in sign3.
function sign3_Callback(hObject, eventdata, handles)
% hObject    handle to sign3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns sign3 contents as cell array
%        contents{get(hObject,'Value')} returns selected item from sign3


% --- Executes during object creation, after setting all properties.
function sign3_CreateFcn(hObject, eventdata, handles)
% hObject    handle to sign3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in sign4.
function sign4_Callback(hObject, eventdata, handles)
% hObject    handle to sign4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns sign4 contents as cell array
%        contents{get(hObject,'Value')} returns selected item from sign4


% --- Executes during object creation, after setting all properties.
function sign4_CreateFcn(hObject, eventdata, handles)
% hObject    handle to sign4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in sign5.
function sign5_Callback(hObject, eventdata, handles)
% hObject    handle to sign5 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns sign5 contents as cell array
%        contents{get(hObject,'Value')} returns selected item from sign5


% --- Executes during object creation, after setting all properties.
function sign5_CreateFcn(hObject, eventdata, handles)
% hObject    handle to sign5 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in calculate.
function calculate_Callback(hObject, eventdata, handles)
% hObject    handle to calculate (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on selection change in total_nums.
contents = cellstr(get(handles.total_nums, 'String'));
operation1 = cellstr(get(handles.sign1, 'String'));
operation2 = cellstr(get(handles.sign2, 'String'));
operation3 = cellstr(get(handles.sign3, 'String'));
operation4 = cellstr(get(handles.sign4, 'String'));
operation5 = cellstr(get(handles.sign5, 'String'));

if contents{get(handles.total_nums, 'Value')} == string('2')
    n1 = get(handles.num1, 'string');
    n2 = get(handles.num2, 'string');

    sgn1 = operation1{get(handles.sign1, 'Value')};

    set(handles.ans, 'string', eval(char(strcat(n1, sgn1, n2))));

elseif contents{get(handles.total_nums, 'Value')} == string('3')
    n1 = get(handles.num1, 'string');
    n2 = get(handles.num2, 'string');
    n3 = get(handles.num3, 'string');

    sgn1 = operation1{get(handles.sign1, 'Value')};
    sgn2 = operation2{get(handles.sign2, 'Value')};
        
    set(handles.ans, 'string', ...
                   eval(char(strcat(n1, sgn1, n2, sgn2, n3))));

elseif contents{get(handles.total_nums, 'Value')} == string('4')
    n1 = get(handles.num1, 'string');
    n2 = get(handles.num2, 'string');
    n3 = get(handles.num3, 'string');
    n4 = get(handles.num4, 'string');

    sgn1 = operation1{get(handles.sign1, 'Value')};
    sgn2 = operation2{get(handles.sign2, 'Value')};
    sgn3 = operation3{get(handles.sign3, 'Value')};

    set(handles.ans, 'string', ...
                 eval(char(strcat(n1, sgn1, n2, sgn2, n3, sgn3, n4))));

elseif contents{get(handles.total_nums, 'Value')} == string('5')
    n1 = get(handles.num1, 'string');
    n2 = get(handles.num2, 'string');
    n3 = get(handles.num3, 'string');
    n4 = get(handles.num4, 'string');
    n5 = get(handles.num5, 'string');

    sgn1 = operation1{get(handles.sign1, 'Value')};
    sgn2 = operation2{get(handles.sign2, 'Value')};
    sgn3 = operation3{get(handles.sign3, 'Value')};
    sgn4 = operation4{get(handles.sign4, 'Value')};

    set(handles.ans, 'string', ...
       eval(char(strcat(n1, sgn1, n2, sgn2, n3, sgn3, n4, sgn4, n5))));

elseif contents{get(handles.total_nums, 'Value')} == string('6')
    n1 = get(handles.num1, 'string');
    n2 = get(handles.num2, 'string');
    n3 = get(handles.num3, 'string');
    n4 = get(handles.num4, 'string');
    n5 = get(handles.num5, 'string');
    n6 = get(handles.num6, 'string');

    sgn1 = operation1{get(handles.sign1, 'Value')};
    sgn2 = operation2{get(handles.sign2, 'Value')};
    sgn3 = operation3{get(handles.sign3, 'Value')};
    sgn4 = operation4{get(handles.sign4, 'Value')};
    sgn5 = operation5{get(handles.sign5, 'Value')};

    set(handles.ans, 'string', ...
    eval(char(strcat(n1, sgn1, n2, sgn2, n3, sgn3, n4, sgn4, n5,...
                                                       sgn5, n6))));
    
end


set(handles.num1, 'Visible', 'on');
set(handles.num2, 'Visible', 'on');
set(handles.num3, 'Visible', 'on');
set(handles.num4, 'Visible', 'on');
set(handles.num5, 'Visible', 'on');
set(handles.num6, 'Visible', 'on');

set(handles.sign1, 'Visible', 'on');
set(handles.sign2, 'Visible', 'on');
set(handles.sign3, 'Visible', 'on');
set(handles.sign4, 'Visible', 'on');
set(handles.sign5, 'Visible', 'on');

function total_nums_Callback(hObject, eventdata, handles)
% hObject    handle to total_nums (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns total_nums contents as cell array
%        contents{get(hObject,'Value')} returns selected item from total_nums


% --- Executes during object creation, after setting all properties.
contents = cellstr(get(handles.total_nums, 'String'));
if contents{get(handles.total_nums, 'Value')} == string('2')
  set(handles.num3, 'Visible', 'off');
  set(handles.num4, 'Visible', 'off');
  set(handles.num5, 'Visible', 'off');
  set(handles.num6, 'Visible', 'off');

  set(handles.sign2, 'Visible', 'off');
  set(handles.sign3, 'Visible', 'off');
  set(handles.sign4, 'Visible', 'off');
  set(handles.sign5, 'Visible', 'off');

elseif contents{get(handles.total_nums, 'Value')} == string('3')
  set(handles.num4, 'Visible', 'off');
  set(handles.num5, 'Visible', 'off');
  set(handles.num6, 'Visible', 'off');

  set(handles.sign3, 'Visible', 'off');
  set(handles.sign4, 'Visible', 'off');
  set(handles.sign5, 'Visible', 'off');

elseif contents{get(handles.total_nums, 'Value')} == string('4')
  set(handles.num5, 'Visible', 'off');
  set(handles.num6, 'Visible', 'off');

  set(handles.sign4, 'Visible', 'off');
  set(handles.sign5, 'Visible', 'off');

elseif contents{get(handles.total_nums, 'Value')} == string('5')
  set(handles.num6, 'Visible', 'off');

  set(handles.sign5, 'Visible', 'off');
  
end


function total_nums_CreateFcn(hObject, eventdata, handles)
% hObject    handle to total_nums (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called
% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
