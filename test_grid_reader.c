#include "grid.h"
#include "grid_reader.h"
#include <stdio.h>
#include <stdlib.h>

int main (){
	//Poniższe dane muszą być dokładnie takie same jak w pliku dane.txt
	int h=3;
	int w=5;
	int cells[3*5] = {0,1,1,0,0
			 ,0,0,0,1,1
			 ,1,1,1,1,1};

	grid_t grid = grid_reader_read("dane.txt");
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
			if (grid->cells[i*w+j]!=cells[i*w+j]){
				printf("Test nieudany\n");
				return 1;
				}
		}
	}
	printf("Test udany\n");
	return 0;
}
