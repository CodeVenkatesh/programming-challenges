#include <tuple>
#include <iostream>

#include <FreeImage.h>
#include "window.h"
#include "plot.h"

using namespace std;

tuple<int, int, int> get_rgb_lin(int n, int max_iterate)
{
	int num_colors = 256;
	int num_3 = pow(num_colors, 3);

	double real = double(n) / double(max_iterate);
	n = (int)(real * double(num_3));

	int r, g, b, k;

	r = k / num_colors;
	g = k - r * num_colors;
	b = n / (pow(num_colors, 2));
	k = n - b * pow(num_colors, 2);

	return make_tuple(r, g, b);
}

tuple<int, int, int> get_rgb_smooth(int n, int max_iterate)
{
	double real = double(n) / double(max_iterate);

	int r = (int)(9 * (1 - real)* pow(real, 3) * 255);
	int g = (int)(15 * pow((1 - real), 2) * pow(real, 2) * 255);
	int b = (int)(8.5 * pow((1 - real), 3) * real * 255);

	return make_tuple(r, g, b);
}

void plot(window<int>& screen, std::vector<int>& colors,
	      int max_iterate, const char *fname, bool smooth_color)
{
#ifndef static_link
	FreeImage_Initialise();
#endif

	FIBITMAP* bitmap = FreeImage_Allocate(screen.length(), screen.width(), 32);

	int k = 0;
	std::tuple<int, int, int> rgb;
	for (int i = screen.get_ymin(); i < screen.get_ymax(); i++) 
	{
		for (int j = screen.get_xmin(); j < screen.get_xmax(); j++) 
		{
			int n = colors.at(k);

			if (!smooth_color)
				rgb = get_rgb_lin(n, max_iterate);
			else {
				rgb = get_rgb_smooth(n, max_iterate);
			}

			RGBQUAD col;
			col.rgbRed = get<0>(rgb);
			col.rgbGreen = get<1>(rgb);
			col.rgbBlue = get<2>(rgb);
			col.rgbReserved = 255;

			FreeImage_SetPixelColor(bitmap, j, i, &col);
			k++;
		}
	}

	FreeImage_Save(FIF_PNG, bitmap, fname, PNG_DEFAULT);
	FreeImage_Unload(bitmap);

#ifdef static_link
	FreeImage_DeInitialise();
#endif
}