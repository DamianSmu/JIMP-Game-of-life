#include "grid.h"
#include <stdio.h>

int main (){
	int h=3;
	int w=5;
	int cells[3*5] = {0,1,1,0,0
			 ,0,0,0,1,1
			 ,1,1,1,1,1};
	grid_t grid = grid_create(h,w,cells);
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
			if (grid->cells[i*h+j]!=cells[i*h+j]){
				printf("Test nieudany\n");
				return 1;
				}
		}
	}
	printf("Test udany\n");
	return 0;
}
