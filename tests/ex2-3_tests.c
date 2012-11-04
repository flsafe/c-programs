#include <ex2-3.c>
#include "minunit.h"

node *push(node *h, int i)
{
	node *new = NULL;

	new = malloc(sizeof(node));
	if(NULL == new) return new;

	new->i = i;
	new->next = h;
	return new;
}

char *list_size_1()
{
	node *list = NULL;

	list = push(list, 3);
	remove_mid_node(list);

	mu_assert(3 == list->i, "Expected list to be unchanged");

	return NULL;
}

char *list_size_2(){
	node *list = NULL;

	list = push(list, 2);
	list = push(list, 1);
	remove_mid_node(list);

	mu_assert(2 == list->i, "Expected first element to be 2");
	mu_assert(NULL == list->next, "Expected list to be size 1");

	return NULL;
}

char *list_size_3()
{
	node *list = NULL;

	list = push(list, 3);
	list = push(list, 2);
	list = push(list, 1);
	remove_mid_node(list->next);

	mu_assert(3 == list->next->i, "Expected first element to be 3");
	mu_assert(NULL == list->next->next, "Expected list to be size 2");

	return NULL;
}

char *all()
{
	mu_suite_start();
	mu_run_test(list_size_1);
	mu_run_test(list_size_2);
	mu_run_test(list_size_3);

	return NULL;
}

RUN_TESTS(all)
