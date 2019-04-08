#include "grid.h"
#include "grid_reader.h"
#include <stdio.h>
#include <stdlib.h>

int main (){
	grid_t grid = grid_reader_read("dane.txt");
	printf("h=%d\n",grid->height);
	printf("w=%d\n",grid->width);
	for (int i=0;i<grid->height;i++){
		for (int j=0;j<grid->width;j++)
			printf("%d ",grid->cells[i*grid->width+j]);
		printf("\n");
	}
	return 0;
}
