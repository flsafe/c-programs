#include <ex3-1.c>
#include "minunit.h"

char *test_1(){
	int ok = 0;
	Stack *s = NULL;

	s = make_stack(3);
	mu_assert(s, "Expected make_stack to return non null");
	
	ok = stack_push(s, 0, 1);
	mu_assert(1 == ok, "Expected return value to be 1");

	ok = stack_push(s, 0, 1);
	mu_assert(0 == ok, "Expected return value to be 0");
	
	return NULL;
}

char *all()
{
	mu_suite_start();

	mu_run_test(test_1);

	return NULL;
}

RUN_TESTS(all)
