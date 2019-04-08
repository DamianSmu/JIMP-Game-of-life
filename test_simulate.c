#include "grid.h"
#include "simulate.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
	grid_t grid = malloc (sizeof *grid);
	grid->height = 5;
	grid->width = 5;
	int cells[25]={0,0,0,0,0,
		       0,0,1,0,0,
		       0,0,1,0,0,
		       0,0,1,0,0,
		       0,0,0,0,0};
	grid->cells=cells;
	grid = simulate_next_gen(grid);
	printf("h=%d\n",grid->height);
	printf("w=%d\n",grid->width);
	for (int i=0;i<grid->height;i++){
		for (int j=0;j<grid->width;j++)
			printf("%d ",grid->cells[i*grid->width+j]);
		printf("\n");
	}
	return 0;
}
