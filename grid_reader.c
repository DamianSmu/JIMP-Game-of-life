#include "grid.h"
#include "grid_reader.h"
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
void grid_reader_read(grid_t grid, char* path){
	FILE *in = fopen(path, "r");
	if (in==NULL){
		printf("Błąd: nie udało się otworzyć pliku o ścieżce: %s\n", path);
		exit(1);
	}
	int n=0;
	int a=0;
	char c;
	if ((a = fscanf(in, "%d %d%c", &grid->height, &grid->width,&c))!=3 ||  c!='\n'){
		printf("Błąd: błędne dane w pliku wejściowym: linia 1. Uważaj na spacje!\n");
		exit(1);
	}
	if (grid->width < 2 || grid->width>10000 || grid->height< 2 || grid->height>10000){
		printf("Błąd: zły rozmiar planszy. Każdy z wymiarów planszy powinien należeć do przedziału <2;10000>\n");
		exit(1);
	}
	grid->cells=malloc(grid->height * grid-> width * sizeof *grid->cells);
	int ln=2;
	int ll=0;
	while ((c=fgetc(in))!=EOF){
		if (c=='\n'){
			ln++;
			ll=0;
		}
		else if (ll>=grid->width){
			printf("Błąd: linia %d jest zbyt długa\n",ln);
			exit(1);
		}
		else if (c=='1' || c=='0'){
			grid->cells[n]=c - '0';
			n++;
			ll++;
		}
		else {
			printf("Błąd: nieoczekiwany znak: %c w linii %d. Uważaj na spacje\n",c,ln);
			exit(1);
		}
	}
		
}
