#include "submodule.h"
#include "io.h"

int init_submodule(submodule* S)
{
	open_movie_file("movie.dat");
	open_schedule_file("schedule.dat");
	
	close_movie_file();
	close_schedule_file();

	return 0;
}