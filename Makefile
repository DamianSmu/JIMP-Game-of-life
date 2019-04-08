life: main.o grid.o grid_reader.o simulate.o grid_text_writer.o grid_png_writer.o
	$(CC) -o life main.o grid.o grid_reader.o simulate.o grid_text_writer.o grid_png_writer.o -lpng

test_grid: test_grid.o grid.o
	$(CC) -o test_grid test_grid.o grid.o

test_grid_reader: test_grid_reader.o grid_reader.o grid.o
	$(CC) -o test_grid_reader test_grid_reader.o grid_reader.o grid.o

test_simulate: test_simulate.o simulate.o grid.o
	$(CC) -o test_simulate test_simulate.o simulate.o grid.o

test_grid_text_writer: test_grid_text_writer.o grid_text_writer.o
	$(CC) -o test_grid_text_writer test_grid_text_writer.o grid_text_writer.o

test_grid_png_writer: test_grid_png_writer.o grid_png_writer.o
	$(CC) -o test_grid_png_writer test_grid_png_writer.o grid_png_writer.o -lpng

.PHONY: clean test_all

test_all: test_simulate test_grid test_grid_reader test_grid_text_writer test_grid_png_writer
	./test_grid
	./test_grid_reader
	./test_simulate
	./test_grid_text_writer
	./test_grid_png_writer

clean:
	-rm *.o
