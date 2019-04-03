#include "grid.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define ALIVE 1
#define DEAD 0

grid_t simulate_next_gen(grid_t grid)
{
    int h = grid -> height;
    int w = grid -> width;
    int* cells = grid -> cells;
    int* new_cells = malloc(sizeof(int)*h*w);
    memcpy(new_cells, cells, sizeof(int)*h*w);
    grid_t new_grid = malloc(sizeof(grid_t));

    new_grid -> cells = new_cells;
    new_grid -> width = w;
    new_grid -> height = h;


    for (int i = 0; i < h;  i++)
    {
        for (int j = 0; j < w; j++)
        {
            int state = cells[i * w + j] ? ALIVE : DEAD;
            int neighbours = 0;

            cells[i*w+((w+j-1)%w)] == ALIVE ? neighbours++ : 0;
            cells[i*w+((w+j+1)%w)] == ALIVE ? neighbours++ : 0;
            cells[((h+i-1)%h)*w+j] == ALIVE ? neighbours++ : 0;
            cells[((h+i+1)%h)*w+j] == ALIVE ? neighbours++ : 0;
            cells[((h+i-1)%h)*w+((w+j-1)%w)] == ALIVE ? neighbours++ : 0;
            cells[((h+i-1)%h)*w+((w+j+1)%w)] == ALIVE ? neighbours++ : 0;
            cells[((h+i+1)%h)*w+((w+j-1)%w)] == ALIVE ? neighbours++ : 0;
            cells[((h+i+1)%h)*w+((w+j+1)%w)] == ALIVE ? neighbours++ : 0;

            if(state == ALIVE)
                new_cells[i*w+j] = ((neighbours == 3 || neighbours == 2) ? ALIVE : DEAD);
            else
                new_cells[i*w+j] = ((neighbours == 3) ? ALIVE : DEAD);
        }
    }
    return new_grid;
}
