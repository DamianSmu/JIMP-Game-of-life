typedef struct {
	int height;
	int width;
	int* cells;
}*grid_t;

grid_t grid_create (int h, int w, int* c);
