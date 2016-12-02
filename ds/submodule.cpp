#include "submodule.h"
#include "io.h"
#include <stdlib.h>

int init_submodule(submodule* S)
{
	int i;
	char movie_name[30];
	int running_time;
	movie* temp;
	// movie.dat 로드
	open_movie_file(&S->io, "movie.dat");
	
	fscanf(S->io.movie_file, "%d", &(S->max_movie));
	S->Movie_data = (movie**)malloc(sizeof(movie*)*(S->max_movie));
	S->Movie_data[0] = NULL;
	for (i = 0; i < S->max_movie; i++) {
		fscanf(S->io.movie_file, "%s %d", movie_name, &running_time);
		add_movie(S, movie_name, running_time);
	}

	close_movie_file(&S->io);
	
	// schedule.dat 로드
	open_schedule_file(&S->io, "schedule.dat");

	close_schedule_file(&S->io);

	return 0;
}

int add_reservation(submodule* S, int rid, schedule* sch)
{
	bst_node* t = (bst_node*)malloc(sizeof(bst_node));
	if (!t) return 0;
	t->rid = rid;
	t->schedule = sch;
	if (!bst_insert(&S->Reservation_data, t)) return 0;

	return 1;
}

int add_movie(submodule* S, char* movie_name, int running_time)
{
	movie* t = (movie*)malloc(sizeof(movie));
	if (!t) return 0;
	movie_init(&t, movie_name);
	t->running_time = running_time;
	S->Movie_data[S->num_movie] = t;
	S->num_movie++;
	return 1;
}

int free_submodule(submodule* S)
{
	int i;
	for (i = 0; i < S->num_movie; i++) {
		free(S->Movie_data[i]);
	}

	return 1;
}

void print_movies(submodule S)
{
	int i;
	movie* temp;
	for (i = 0; i < S.max_movie; i++) {
		temp = S.Movie_data[i];
		printf("[*] Movie %d: \"%s\" - %dmin\n", i + 1, temp->name, temp->running_time);
	}
}