#include <iostream>
#include <chrono>
#include <complex>
#include <functional>
#include <vector>

#include "window.h"
#include "plot.h"
#include "zoom.h"

using namespace std;
typedef complex<double> cd;

/*
TASK: convert pixel coord to complex plane
ARGUMENTS: window<int>&, window<double>&, cd
RETURN: cd
*/
cd scale(window<int>& screen, window<double>& fr, cd c)
{
	cd k(c.real() / (double)screen.width() * fr.width() + fr.get_xmin(),
		 c.imag() / (double)screen.length() * fr.length() + fr.get_ymin());

	return k;
}

/*
TASK: check if point is in set or escapes to infinity (return number if iterating)
ARGUMENTS: cd, int, const function<cd(cd, cd)>&
RETURN: int
*/
int escape(cd c, int max_iterate, const function<cd(cd, cd)>& func) 
{
	cd z(0);
	int iterate = 0;

	while (abs(z) < 2.0 && iterate < max_iterate) 
	{
		z = func(z, c);
		iterate++;
	}

	return iterate;
}

/*
TASK: loop through pixels, check if pixel escapes to infinity
ARGUMENTS: window<int>&, window<double>&, int, vector<int>&, const function<cd(cd, cd)>&
RETURN: void
*/
void get_number_iterations(window<int>& screen, window<double>& fract, int max_iterate, 
	                       vector<int>& colors, const function<cd(cd, cd)>& func) 
{
	int k = 0;
	for (int i = screen.get_ymin(); i < screen.get_ymax(); i++) 
	{
		for (int j = screen.get_xmin(); j < screen.get_xmax(); j++) 
		{
			cd c((double)j, (double)i);
			c = scale(screen, fract, c);
			colors.at(k) = escape(c, max_iterate, func);
			k++;
		}
	}
}

void fractal(window<int>& screen, window<double>& fract, int max_iterate, vector<int>& colors,
	         const function<cd(cd, cd)> &func, const char *fname, bool smooth_color) 
{
	auto start = chrono::steady_clock::now();
	get_number_iterations(screen, fract, max_iterate, colors, func);
	auto end = chrono::steady_clock::now();

	cout << fname << " = " << chrono::duration <double, milli>(end - start).count() << " [ms]" << endl;

	plot(screen, colors, max_iterate, fname, smooth_color);
}

void mandelbrot() 
{
	window<int> screen(0, 1200, 0, 1200);
	window<double> fract(-2.2, 1.2, -1.7, 1.7);

	auto func = [](cd z, cd c)
	{
		return z * z + c; 
	};

	int max_iterate = 500;
	const char *fname = "mandelbrot.png";
	bool smooth_color = true;
	vector<int> colors(screen.screen_size());

	fractal(screen, fract, max_iterate, colors, func, fname, smooth_color);
}

void triple_mandelbrot() 
{
	window<int> screen(0, 1200, 0, 1200);
	window<double> fract(-1.5, 1.5, -1.5, 1.5);

	auto func = [](cd z, cd c) 
	{
		return z * z * z + c; 
	};

	int max_iterate = 500;
	const char *fname = "triple_mandelbrot.png";
	bool smooth_color = true;
	vector<int> colors(screen.screen_size());

	fractal(screen, fract, max_iterate, colors, func, fname, smooth_color);
}

int main()
{
	mandelbrot();
	triple_mandelbrot();

	system("pause");
	return 0;
}