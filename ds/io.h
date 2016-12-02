#pragma once

#include <stdio.h>
#include "movie.h"

typedef struct io_module_ {
	FILE* movie_file;
	FILE* schedule_file;
} io_module;

int open_movie_file(io_module* io, char* filename);
int open_schedule_file(io_module* io, char* filename);
int close_movie_file();
int close_schedule_file();

movie* load_one_movie(FILE* mf);