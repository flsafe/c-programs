#include <ex3-1.c>
#include "minunit.h"

char *test_push(){
	int ok = 0;
	Stack *s = NULL;

	s = make_stack(3);
	mu_assert(s, "Expected make_stack to return non null");

	ok = stack_push(s, 0, 1);
	mu_assert(1 == ok, "Expected return value to be 1");

	ok = stack_push(s, 0, 1);
	mu_assert(0 == ok, "Expected return value to be 0");

	ok = stack_push(s, 1, 1);
	mu_assert(1 == ok, "Expected push(1,1) return value to be 1");
	
	ok = stack_push(s, 1, 1);
	mu_assert(0 == ok, "Expected push(1,1) return value to be 0");

	ok = stack_push(s, 2, 1);
	mu_assert(1 == ok, "Expected push(2,1) return value to be 1");
	
	ok = stack_push(s, 2, 1);
	mu_assert(0 == ok, "Expected push(2,1) return value to be 0");
	
	return NULL;
}

char *test_pop(){
	int err = 0, val;
	Stack *s = NULL;

	s = make_stack(3);
	val = stack_pop(s, 0, &err);
	mu_assert(0 == val, "Expected pop empty stack to return 0");
	mu_assert(1 == err, "Expected pop empty stack to return error code 1");
	
	stack_push(s, 0, 100);
	stack_push(s, 0, 500); /* Should be ignored by stack API */
	val = stack_pop(s, 0, &err);
	mu_assert(100 == val, "Expected push(100), pop() to return 100");
	mu_assert(0 == err, "Expected push(100), pop() error code to return 0");
	
	return NULL;
}

char *all()
{
	mu_suite_start();

	mu_run_test(test_push);
	mu_run_test(test_pop);

	return NULL;
}

RUN_TESTS(all)
