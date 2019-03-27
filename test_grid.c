#include "grid.h"
#include <stdio.h>

int main (){
	int h=3;
	int w=5;
	int cells[3*5] = {0,1,1,0,0,0,0,0,1,1,1,1,1,1,1};
	grid_t grid = grid_create(h,w,cells);
	printf("h=%d\n",h);
	printf("w=%d\n",w);
	for (int i=0;i<h;i++){
		for (int j=0;j<w;j++)
			printf("%d ",cells[i*w+j]);
		printf("\n");
	}
	return 0;
}
