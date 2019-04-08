#include "grid.h"
#include "grid_reader.h"
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
grid_t grid_reader_read( char* path){
	FILE *in = fopen(path, "r");
	if (in==NULL){
		printf("Błąd: nie udało się otworzyć pliku o ścieżce: %s\n", path);
		exit(1);
	}
	int h;
	int w;
	int n=0;
	char c;
	if ((fscanf(in, "%d %d%c", &h, &w ,&c))!=3 ||  c!='\n'){
		printf("Błąd: błędne dane w pliku wejściowym: linia 1. Uważaj na spacje!\n");
		exit(1);
	}
	if (w < 2 || w >10000 || h < 2 || h > 10000){
		printf("Błąd: zły rozmiar planszy. Każdy z wymiarów planszy powinien należeć do przedziału <2;10000>\n");
		exit(1);
	}
	int *cells=malloc(h*w * sizeof *cells);
	int ln=2;
	int ll=0;
	while ((c=fgetc(in))!=EOF){
		if (c=='\n'){
			ln++;
			ll=0;
		}
		else if (ln>h+1){
			printf("Błąd: zbyt wiele linii w pliku. Plik powinien zawierać %d linii\n",h+1);
			exit(1);
		}
		else if (ll>=w){
			printf("Błąd: linia %d jest zbyt długa\n",ln);
			exit(1);
		}
		else if (c=='1' || c=='0'){
			cells[n]=c - '0';
			n++;
			ll++;
		}
		else {
			printf("Błąd: nieoczekiwany znak: %c w linii %d. Uważaj na spacje\n",c,ln);
			exit(1);
		}
	}
	return grid_create(h,w,cells);
		
}
