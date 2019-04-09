#include "grid_png_writer.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int c[15]={0,1,1,0,0,0,0,0,1,1,1,1,1,1,1};
  grid_png_writer_generate("gen01.png",3,5,c);
  printf("Jeśli poniżej nic się nie wyświetli, to test udany:\n");
  system("diff gen01.png expected.png");

  return 0;
}

