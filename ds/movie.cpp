#include "movie.h"
#include <stdlib.h>
#include <string.h>
movie* movie_init(movie** mv, char* name)
{
	int len = strlen(name);
	(*mv)->name = (char*)malloc(len + 1);
	// 예외 처리
	if ((*mv)->name == NULL) return NULL;

	strcpy((*mv)->name, name);

	return (*mv);
}

schedule* schedule_init(schedule** t, movie* mv, int st) 
{
	int i;
	(*t)->movie = mv;
	(*t)->starting_time = st;
	(*t)->ending_time = st + mv->running_time;
	for (i = 0; i < SEATS_MAX; i++) {
		(*t)->seats[i] = AVAILABLE;
	}
	(*t)->next_movie = NULL;
	(*t)->prev_movie = NULL;
	
	return *t;
}

schedule* schedule_insert(schedule* head, schedule* t)
{
	schedule* s = head;
	while (s->next_movie) 
		s = s->next_movie;
	s->next_movie = t;
	t->prev_movie = s;

	return t;
}