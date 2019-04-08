#include "grid_text_writer.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
	int height=3;
	int width=5;
	int cells[15]={0,1,1,0,0
		  ,0,0,0,1,1
		  ,1,1,1,1,1};
	grid_text_writer_write("gen01.txt",height,width,cells);
	printf("Jeśli poniżej nic się nie wyświetli, to test udany:\n");
	system("diff gen01.txt expected.txt");
	return 0;
}
