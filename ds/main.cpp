#include <stdio.h>
#include "submodule.h"
#include "io.h"
#include <stdlib.h>

void bst_test();
void submodule_test();

submodule Submodule;

int main()
{
	submodule_test();

	return 0;
}

void bst_test()
{
	bst_node* test;
	test = (bst_node*)malloc(sizeof(bst_node));
	test->rid = 10;
	printf("[*] test->rid = 10\n");
	bst_insert(&Submodule.Reservation_data, test);
	printf("[*] bst_insert(&Submodule.Reservation_data, test)\n");
	bst_node* s;
	s = bst_search(Submodule.Reservation_data, 10);
	printf("[*] s = bst_search(Submodule.Reservation_data, 10)\n");
	printf("[*] s->rid: %d\n", s->rid);

	free(test);
}

void submodule_test()
{
	init_submodule(&Submodule);
	print_movies(Submodule);
	print_schedules(Submodule);
	free_submodule(&Submodule);
}