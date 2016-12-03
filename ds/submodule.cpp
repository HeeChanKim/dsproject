#include "submodule.h"
#include "io.h"
#include <stdlib.h>

int init_submodule(submodule* S)
{
	int i, j;
	char movie_name[30];
	int running_time;
	int num_schedule;
	int starting_time;
	int movie_number;
	movie* temp;
	// movie.dat 로드
	open_movie_file(&S->io, "movie.dat");
	
	fscanf(S->io.movie_file, "%d", &(S->max_movie));
	S->Movie_data = (movie**)malloc(sizeof(movie*)*(S->max_movie));
	for (i = 0; i < S->max_movie; i++) {
		fscanf(S->io.movie_file, "%s %d", movie_name, &running_time);
		add_movie(S, movie_name, running_time);
	}

	close_movie_file(&S->io);
	
	// schedule.dat 로드
	open_schedule_file(&S->io, "schedule.dat");
	
	fscanf(S->io.schedule_file, "%d", &(S->day_schedule));
	S->Schedule = (schedule**)malloc(sizeof(schedule*)*(S->day_schedule));
	for (i = 0; i < S->day_schedule; i++) {
		S->Schedule[i] = (schedule*)malloc(sizeof(schedule));
		S->Schedule[i]->next_movie = NULL;
		S->Schedule[i]->prev_movie = NULL;
		fscanf(S->io.schedule_file, "%d %d", &num_schedule, &starting_time);
		for (j = 0; j < num_schedule; j++) {
			fscanf(S->io.schedule_file, "%d", &movie_number);
			add_schedule(S, S->Schedule[i], S->Movie_data[movie_number], starting_time);
			starting_time += S->Movie_data[movie_number]->running_time + 10;
		}
	}
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
	if (!movie_init(&t, movie_name)) return 0;
	t->running_time = running_time;
	S->Movie_data[S->num_movie] = t;
	S->num_movie++;
	return 1;
}

int free_submodule(submodule* S)
{
	int i;
	schedule* t;
	for (i = 0; i < S->num_movie; i++) {
		free(S->Movie_data[i]);
	}
	for (i = 0; i < S->day_schedule; i++) {
		while (S->Schedule[i]) {
			t = S->Schedule[i];
			while (t->next_movie)
				t = t->next_movie;
			if (t->prev_movie) t->prev_movie->next_movie = NULL;
			else break;
			free(t);
		}
	}
	free(S->Schedule);

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

int add_schedule(submodule* S, schedule* head, movie* mv, int st)
{
	schedule* t = (schedule*)malloc(sizeof(schedule));
	if (!t) return 0;
	if (!schedule_init(&t, mv, st)) return 0;
	if (!schedule_insert(head, t)) return 0;

	return 1;
}

void print_schedules(submodule S)
{
	int i;
	schedule* temp;
	for (i = 0; i < S.day_schedule; i++) {
		temp = S.Schedule[i]->next_movie;
		printf("[*] Day %d\n", i + 1);
		while (temp) {
			printf("[*] %d ~ %d : %s \n", temp->starting_time, temp->ending_time, temp->movie->name);
			temp = temp->next_movie;
		}
	}
}