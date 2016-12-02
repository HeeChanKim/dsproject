#pragma once

#include "bst.h"
#include "io.h"

const int MOVIE_MAX = 20;

typedef struct submodule_
{
	io_module io;
	schedule* Schedule;
	bst_node* Reservation_data;
	movie* Movie_data[MOVIE_MAX];
} submodule;

int init_submodule(submodule* S);