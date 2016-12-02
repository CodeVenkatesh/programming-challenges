#ifndef windowh
#define windowh

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

	T length() const { return this->_xmax - this->_xmin; }
	T width() const { return this->_ymax - this->_ymin; }
	T screen_size() const { return length() * width(); }

	void reset_all(T x_min, T x_max, T y_min, T y_max) 
	{
		this->_xmin = x_min;
		this->_xmax = x_max;
		this->_ymin = y_min;
		this->_ymax = y_max;
	}

	window(T xmin, T xmax, T ymin, T ymax) :
		_xmin(xmin), _xmax(xmax), _ymin(ymin), _ymax(ymax) {}
};

#endif