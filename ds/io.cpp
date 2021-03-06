#include "io.h"
#include <stdlib.h>
#include <stdio.h>
int open_movie_file(io_module* io, char* filename)
{ 
	io->movie_file = fopen(filename, "rt");
	if (!io->movie_file) return 0;

	return 1;
}
int open_schedule_file(io_module* io, char* filename) 
{ 
	io->schedule_file= fopen(filename, "rt");
	if (!io->schedule_file) return 0;

	return 1;
}
int close_movie_file(io_module* io) 
{ 
	int ret = fclose(io->movie_file);
	if (ret)
		return 0;

	return 1;
}
int close_schedule_file(io_module* io) 
{
	int ret = fclose(io->schedule_file);
	if (ret)
		return 0;

	return 1;
}
movie* load_one_movie(FILE* mf) { return NULL; }