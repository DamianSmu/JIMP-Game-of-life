#include "grid.h"
#include "grid.c"
#include <string.h>
#include <stdio.h>

grid_t simulate_next_gen(grid_t grid)
{
    int h = grid -> height;
    int w = grid -> width;
    int* cells = grid -> cells;

    int* new_cells = malloc(sizeof(cells));
    memcpy(new_cells, grid -> cells, sizeof(cells));

    grid_t new_grid = grid_create(h, w, new_cells);

    for (int i = 0; i < h;  i++)
    {
        for (int j = 0; j < w; ++j)
        {
            int state = cells[i * w + j] == 1 ? 1 : 0;
            int neighbours = 0;

            cells[i*w+(w+j-1)%w] == 1 ? neighbours++ : 0;
            cells[i*w+(w+j+1)%w] == 1 ? neighbours++ : 0;
            cells[(h+i-1)%h*w+j] == 1 ? neighbours++ : 0;
            cells[(h+i+1)%h*w+j] == 1 ? neighbours++ : 0;
            cells[(h+i-1)%h*w+(w+j-1)%w] == 1 ? neighbours++ : 0;
            cells[(h+i-1)%h*w+(w+j+1)%w] == 1 ? neighbours++ : 0;
            cells[(h+i+1)%h*w+(w+j-1)%w] == 1 ? neighbours++ : 0;
            cells[(h+i+1)%h*w+(w+j+1)%w] == 1 ? neighbours++ : 0;

            new_cells[i*w+j] = state == 0 && neighbours == 3 ? 1 : 0;
            new_cells[i*w+j] = state == 1 && (neighbours == 3 || neighbours == 2) ? 1 : 0;

            //printf("%d , %d  - %d - s: %d\n",i, j, neighbours, state);
        }
    }
    return new_grid;
}