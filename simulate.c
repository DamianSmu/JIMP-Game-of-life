#include "grid.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

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
            int state = cells[i * w + j] ? 1 : 0;
            int neighbours = 0;

            cells[i*w+((w+j-1)%w)] == 1 ? neighbours++ : 0;
            cells[i*w+((w+j+1)%w)] == 1 ? neighbours++ : 0;
            cells[((h+i-1)%h)*w+j] == 1 ? neighbours++ : 0;
            cells[((h+i+1)%h)*w+j] == 1 ? neighbours++ : 0;
            cells[((h+i-1)%h)*w+((w+j-1)%w)] == 1 ? neighbours++ : 0;
            cells[((h+i-1)%h)*w+((w+j+1)%w)] == 1 ? neighbours++ : 0;
            cells[((h+i+1)%h)*w+((w+j-1)%w)] == 1 ? neighbours++ : 0;
            cells[((h+i+1)%h)*w+((w+j+1)%w)] == 1 ? neighbours++ : 0;

            if(state == 1)
                new_cells[i*w+j] = ((neighbours == 3 || neighbours == 2) ? 1 : 0);
            else
                new_cells[i*w+j] = ((neighbours == 3) ? 1 : 0);


           // printf("%d , %d  - %d - s: %d\n",i, j, neighbours, state);
        }
    }

   /* for (int i = 0; i < h;  i++)
    {
        for (int j = 0; j < w; j++)
        {
            int state = new_cells[i * w + j];
            printf("%d", state);
        }
        printf("\n");
    }
    printf("\n\n");*/

    return new_grid;
}
