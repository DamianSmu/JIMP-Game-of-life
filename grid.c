#include "grid.h"
#include <stdlib.h>

grid_t grid_create(int h, int w, int* cells){
	grid_t grid = malloc(sizeof *grid);
	grid->height=h;
	grid->width=w;
	grid->cells=malloc(h*w*sizeof *cells);
}
