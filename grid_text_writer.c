#include "grid_text_writer.h"
#include <stdio.h>
#include <stdlib.h>
void grid_text_writer_write (char* path,int height, int width, int* cells){
	FILE *out = fopen(path, "w");
	if (out==NULL){
		printf("Błąd: nie udało się otworzyć pliku o ścieżce: %s\n", path);
		exit(1);
	}
	fprintf(out, "%d %d\n",height, width);
	for (int i=0;i<height;i++){
		for (int j=0;j<width;j++)
			fprintf(out,"%d",cells[i*width+j]);
		fprintf(out,"\n");
	}
	fclose(out);
}
