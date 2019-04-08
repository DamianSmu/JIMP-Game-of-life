#include "grid.h"
#include "simulate.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
	grid_t grid = malloc (sizeof *grid);
	grid->height = 5;
	grid->width = 5;
	int h=grid->height;
	int w=grid->width;
	int cells[25]={0,0,0,0,0,
		       0,0,1,0,0,
		       0,0,1,0,0,
		       0,0,1,0,0,
		       0,0,0,0,0};
	int expected_cells[25]= {0,0,0,0,0,
		      		 0,0,0,0,0,
		       		 0,1,1,1,0,
		       		 0,0,0,0,0,
		     		 0,0,0,0,0};
	grid->cells=cells;
	grid_t next_grid = simulate_next_gen(grid);
	if (next_grid->height != h){
		return 1;
		printf("Test nieudany\n");
	}
	if (next_grid->width != w){
		return 1;
		printf("Test nieudany\n");
	}
	for (int i=0;i<h;i++){
		for (int j=0;j<w;j++){
			if (next_grid->cells[i*w+j]!=expected_cells[i*w+j]){
				printf("Test nieudany\n");
				return 1;
				}
		}
	}
	printf("Test udany\n");
	return 0;
}
