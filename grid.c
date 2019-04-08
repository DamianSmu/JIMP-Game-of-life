#include "grid.h"
#include <stdlib.h>
#include <string.h>

grid_t grid_create(int h, int w, int* cells){
	grid_t grid = malloc(sizeof *grid);
	grid->height=h;
	grid->width=w;
	grid->cells=malloc(h*w*sizeof *cells);
	memcpy(grid->cells, cells, grid->height*grid->width*sizeof*cells);
	return grid;
}
