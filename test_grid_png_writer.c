#include "grid_png_writer.h"

int main() {
  int c[15]={0,1,1,0,0,0,0,0,1,1,1,1,1,1,1};
  grid_png_writer_generate("out.png",3,5,c);

  return 0;
}

