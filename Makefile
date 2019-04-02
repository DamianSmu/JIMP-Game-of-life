test_grid_png_writer: test_grid_png_writer.o grid_png_writer.o
	$(CC) -o test_grid_png_writer test_grid_png_writer.o grid_png_writer.o -lpng
