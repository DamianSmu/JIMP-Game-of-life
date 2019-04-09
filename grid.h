#ifndef GRID_H
#define GRID_H

typedef struct {
	int height;
	int width;
	int* cells;
}*grid_t;

grid_t grid_create (int h, int w, int* c);

void grid_free (grid_t grid);
#endif
