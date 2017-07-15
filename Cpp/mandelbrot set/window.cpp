template<typename T>
class window
{
private:
	T _xmin, _xmax, _ymin, _ymax;

public:
	T get_xmin() { return this->_xmin; }
	void set_xmin(T xmin) { this->_xmin = xmin; }
	
	T get_xmax() { return this->_xmax; }
	void set_xmax(T xmax) { this->_xmax = xmax; }
	
	T get_ymin() { return this->_ymin; }
	void set_ymin(T ymin) { this->_ymin = ymin; }
	
	T get_ymax() { return this->_ymax; }
	void set_ymax(T ymax) { this->_ymax = ymax; }

	window(T xmin, T xmax, T ymin, T ymax) :
		_xmin(xmin), _xmax(xmax), _ymin(ymin), _ymax(ymax) {}
};