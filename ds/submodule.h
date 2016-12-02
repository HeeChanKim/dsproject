#pragma once

#include "bst.h"
#include "io.h"

typedef struct submodule_
{
	io_module io;
	schedule** Schedule;
	movie** Movie_data;
	bst_node* Reservation_data;

	int num_movie;
	int max_movie;
} submodule;

int init_submodule(submodule* S);
int add_reservation(submodule* S, int rid, schedule* sch);
int add_movie(submodule* S, char* movie_name, int running_time);
int free_submodule(submodule* S);

void print_movies(submodule S);