#include <ex2-2.c>
#include "minunit.h"

int push(node **list, int i)
{
	node *new = malloc(sizeof(node));
	if(NULL == new) return 0;

	new->i = i;
	new->next = *list;
	*list = new;

	return 1;
}

char *test_list_len1()
{
	int r = 0;
	node *list = NULL;

	mu_assert(push(&list, 1), "Test setup failed");

	mu_assert(list == get_nth_to_last(list, 1), "Failed get 1th to last, list len 1");
	
	return NULL;
}

char *test_list_nth_past_len1()
{
	node *list = NULL;

	mu_assert(push(&list, 1), "Test setup failed");

	mu_assert(NULL == get_nth_to_last(list, 2), "Failed reutrn null, list len 1");
	
	return NULL;
}

char *test_nth_len4()
{
	int r = 0;
	node *list = NULL, *n = NULL;

	mu_assert(push(&list, 1), "Test setup failed");
	mu_assert(push(&list, 2), "Test setup failed");
	mu_assert(push(&list, 3), "Test setup failed");
	mu_assert(push(&list, 4), "Test setup failed");

	mu_assert(n = get_nth_to_last(list, 2), "Failed get node 2nd to last, list len 4");
	mu_assert(2 == n->i, "Failed to get 2nd to last, list len 4");
	
	return NULL;
}

char *all()
{
	mu_suite_start();

	mu_run_test(test_list_len1);
	mu_run_test(test_list_nth_past_len1);
	mu_run_test(test_nth_len4);

	return NULL;
}

RUN_TESTS(all)
