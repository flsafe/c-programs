#include <ex3-3.c>
#include "minunit.h"

char *test_push(){
	int ok = 0;
	multistack *s = NULL;

	s = new_multistack(1);
	mu_assert(s, "Expected make_stack to return non null");

	ok = push_multistack(s, 1);
	mu_assert(1 == ok, "Expected return value to be 1");

	ok = push_multistack(s, 2);
	mu_assert(1 == ok, "Expected return value to be 1");

	ok = push_multistack(s, 3);
	mu_assert(1 == ok, "Expected return value to be 1");

	mu_assert(s->size == 3, "Expected stack size to be 3");

	return NULL;
}

char *test_pop(){
	int ok = 0, val = 0;
	multistack *s = NULL;

	s = new_multistack(1);

	push_multistack(s, 3);
	push_multistack(s, 2);
	push_multistack(s, 1);

	ok = pop_multistack(s, &val);
	mu_assert(ok, "Expected return value to be 1");
	mu_assert(1 == val, "Expected return value to be 1");

	ok = pop_multistack(s, &val);
	mu_assert(ok, "Expected return value to be 1");
	mu_assert(2 == val, "Expected return value to be 2");

	ok = pop_multistack(s, &val);
	mu_assert(ok, "Expected return value to be 1");
	mu_assert(3 == val, "Expected return value to be 3");

	mu_assert(s->size == 0, "Expected stack size to be 3");

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
