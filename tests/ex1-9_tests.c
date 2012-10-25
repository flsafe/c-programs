#include <ex1-9.c>
#include "minunit.h"

node *push(int i, node *list)
{
	node *new = NULL;

	new = malloc(sizeof(node));
	if(!new) return NULL;

	new->i = i;
	new->next = list;

	return new;
}

int list_len(node *list)
{
	int count = 0;
	node *curr = NULL;

	for(curr = list ; curr ; curr = curr->next){
		count++;	
	}

	return count;
}

int list_count(node *list, int i)
{
	int count = 0;
	node *curr = NULL;

	for(curr = list ; curr ; curr = curr->next){
		if(i == curr->i){
			count++;	
		}
	}

	return count;
}

char *test_list_1()
{
	node *list = NULL;

	list = push(1, list);
	remove_duplicates(&list);

	mu_assert(1 == list->i, "Excpected list of size 1 to contain value 1");
	mu_assert(NULL == list->next, "Expected list of size 1");

	return NULL;
}

char *test_with_duplicates()
{
	node *list = NULL;

	list = push(1, list);
	list = push(2, list);
	list = push(1, list);

	remove_duplicates(&list);

	mu_assert(2 == list_len(list), "Expected list len to be 2");
	mu_assert(1 == list_count(list, 1), "Expected list to have 1 value 1");
	mu_assert(1 == list_count(list, 2), "Expected list to have 1 value 2");

	return NULL;
}

char *test_without_duplicates()
{
	node *list = NULL;

	list = push(1, list);
	list = push(2, list);
	list = push(3, list);

	remove_duplicates(&list);

	mu_assert(3 == list_len(list), "Expected list len to be 2");
	mu_assert(1 == list_count(list, 1), "Expected list to have 1 value 1");
	mu_assert(1 == list_count(list, 2), "Expected list to have 1 value 2");
	mu_assert(1 == list_count(list, 3), "Expected list to have 1 value 3");

	return NULL;
}

char *test_with_empty()
{
	node *list = NULL;

	remove_duplicates(&list);
	mu_assert(NULL == list, "Failed with empty list, expected NULL");

	return NULL;
}

char *all()
{
	mu_suite_start();

	mu_run_test(test_list_1);
	mu_run_test(test_with_duplicates);
	mu_run_test(test_without_duplicates);
	mu_run_test(test_with_empty);

	return NULL;
}

RUN_TESTS(all)
