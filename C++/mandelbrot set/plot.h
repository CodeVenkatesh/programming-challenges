#include <vector>

#ifndef ploth
#define ploth

#include "window.h"

void plot(window<int>& screen, std::vector<int>& colors, 
	      int max_iterate, const char *fname, bool smooth_color);

#endif