#include <ex3-2.c>
#include "minunit.h"

char *test_push(){
	int ok = 0;
	Stack *s = NULL;

	s = new_stack(1);
	mu_assert(s, "Expected make_stack to return non null");

	ok = push(s, 1);
	mu_assert(1 == ok, "Expected return value to be 1");

	ok = push(s, 2);
	mu_assert(0 == ok, "Expected return value to be 0");

	return NULL;
}

char *test_pop(){
	int ok = 0, val = 100;
	Stack *s = NULL;

	s = new_stack(1);
	ok = pop(s, &val);
	mu_assert(0 == ok, "Expected pop empty stack to return 0");
	mu_assert(100 == val, "Expected pop empty stack leave val unchanged");

	ok = push(s, val);
	mu_assert(1 == ok, "Expected push to return 1");
	ok = pop(s, &val);
	mu_assert(1 == ok, "Expected pop to return 1");
	mu_assert(100 == val, "Expected pop to set val to 100");

	return NULL;
}

char *test_min(){
	int ok = 0, ignore = 0, cur_min = -1;
	MinStack *s = NULL;

	s = malloc(sizeof(MinStack));
	s->data_stack = new_stack(100);
	s->min_stack = new_stack(100);

	mpush(s, 100);
	mpush(s, 3);
	mpush(s, 3);
	mpush(s, 5);
	mpush(s, 1);
	mpush(s, 1);

	/* 1, 1, 5, 3, 3, 100 */
	ok = min(s, &cur_min);
	mu_assert(ok, "Expected pop to return 1");
	printf("cur_min: %d\n", cur_min);
	mu_assert(1 == cur_min, "Expected cur_min to be 1");

	/* 1, 5, 3, 3, 100 */
	mpop(s, &ignore);
	ok = min(s, &cur_min);
	mu_assert(ok, "Expected min to return 1");
	mu_assert(1 == cur_min, "Expected val to be 1");

	/* 5, 3, 3, 100 */
	mpop(s, &ignore);
	ok = min(s, &cur_min);
	mu_assert(ok, "Expected min to return 1");
	mu_assert(3 == cur_min, "Expected val to be 1");

	/* 3, 3, 100 */
	mpop(s, &ignore);
	ok = min(s, &cur_min);
	mu_assert(ok, "Expected min to return 1");
	mu_assert(3 == cur_min, "Expected val to be 1");

	/* 3, 100 */
	mpop(s, &ignore);
	ok = min(s, &cur_min);
	mu_assert(ok, "Expected min to return 1");
	mu_assert(3 == cur_min, "Expected val to be 1");

	/* 100 */
	mpop(s, &ignore);
	ok = min(s, &cur_min);
	mu_assert(ok, "Expected min to return 1");
	mu_assert(100 == cur_min, "Expected val to be 1");

	/* [empty] */
	mpop(s, &ignore);
	ok = min(s, &cur_min);
	mu_assert(0 == ok, "Expected min to return 0");

	return NULL;
}

char *all()
{
	mu_suite_start();

	mu_run_test(test_push);
	mu_run_test(test_pop);
	mu_run_test(test_min);

	return NULL;
}

RUN_TESTS(all)
