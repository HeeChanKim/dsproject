#pragma once

#include "bst.h"
#include "io.h"

typedef struct submodule_
{
	io_module io;
	schedule** Schedule;
	movie** Movie_data;
	bst_node* Reservation_data;

	int num_movie; // ���� �ε�� ��ȭ ��
	int max_movie; // ��ȭ �ִ� ��
	int day_schedule; // ��ĥ���� �������ΰ�
} submodule;

int init_submodule(submodule* S);
int add_reservation(submodule* S, int rid, schedule* sch);
int add_movie(submodule* S, char* movie_name, int running_time);
int add_schedule(submodule* S, schedule* head, movie* mv, int st);
int free_submodule(submodule* S);

void print_movies(submodule S);
void print_schedules(submodule S);