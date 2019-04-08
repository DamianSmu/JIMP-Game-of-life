#include "grid.h"
#include "simulate.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
	int h=5;
	int w=5;
	int cells[25]={0,0,0,0,0,
		       0,0,1,0,0,
		       0,0,1,0,0,
		       0,0,1,0,0,
		       0,0,0,0,0};
	grid_t grid = grid_create(h,w,cells);
	int expected_cells[25]= {0,0,0,0,0,
		      		 0,0,0,0,0,
		       		 0,1,1,1,0,
		       		 0,0,0,0,0,
		     		 0,0,0,0,0};
	grid = simulate_next_gen(grid);
	if (grid->height != h){
		return 1;
		printf("Test nieudany\n");
	}
	if (grid->width != w){
		return 1;
		printf("Test nieudany\n");
	}
	for (int i=0;i<h;i++){
		for (int j=0;j<w;j++){
			if (grid->cells[i*w+j]!=expected_cells[i*w+j]){
				printf("Test nieudany\n");
				return 1;
				}
		}
	}
	printf("Test udany\n");
	grid_free(grid);
	return 0;
}
