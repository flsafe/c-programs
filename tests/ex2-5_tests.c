#include <ex2-5.c>
#include "minunit.h"

node *push(int i, node *h)
{
	node *new = NULL;

	new = malloc(sizeof(node));
	if(!new) return NULL;

	new->i = i;
	new->next = h;

	return new;
}

node *get_ith(int i, node *h)
{
	node *curr = NULL;
	int n = 0;

	curr = h;
	for(n = 0 ; curr && n < i ; n++){
		curr = curr->next;	
	}

	return curr;
}

char *test_cycle()
{
	int i = 0;
	node *list = NULL, *last = NULL, *begin = NULL;

	for(i = 100 ; i > 0 ; i--){
		list = push(i, list);
	}

	last = get_ith(99, list);
	begin = get_ith(4, list);
	last->next = begin;

	mu_assert(begin == get_cyc_start(list), "Failed with cycle");

	return NULL;
}

char *test_no_cycle()
{
	int i = 0;
	node *list = NULL;

	for(i = 100 ; i > 0 ; i--){
		list = push(i, list);
	}

	mu_assert(NULL == get_cyc_start(list), "Failed with cycle");

	return NULL;
}

char *all()
{
	mu_suite_start();
	mu_run_test(test_cycle);
	mu_run_test(test_no_cycle);

	return NULL;
}

RUN_TESTS(all)
