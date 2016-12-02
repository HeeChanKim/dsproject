#include "movie.h"
#include <stdlib.h>
#include <string.h>
movie* movie_init(movie** mv, char* name)
{
	int len = strlen(name);
	(*mv)->name = (char*)malloc(len + 1);
	// 예외 처리
	if ((*mv)->name == NULL) return 0;

	strcpy((*mv)->name, name);

	return (*mv);
}

schedule* schedule_init(schedule* t, movie* mv, int rn) { return NULL; }
schedule* schedule_insert(schedule* head, schedule* t) { return NULL; }
int schedule_delete(schedule* head, schedule* t) { return 0; }