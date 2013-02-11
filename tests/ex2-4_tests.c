#include <stdio.h>
#include "minunit.h"
#include "ex2-4.c"

char *test_99_plus_99()
{
	node *op1 = NULL;
	node *op2 = NULL;
	node *result = NULL;

	append(&op1, 9); append(&op1, 9);
	append(&op2, 9); append(&op2, 9);

	result = sum_lists(op1, op2);
	
	mu_assert(NULL != result, "result should not be NULL");
	mu_assert(8 == result->i, "Result[0] should be 8"); 
	result=result->next;
	mu_assert(NULL != result, "result should not be NULL");
	
	mu_assert(9 == result->i, "Result[1] should be 9"); 
	result=result->next;
	mu_assert(NULL != result, "result should not be NULL");

	mu_assert(1 == result->i, "Result[2] should be 1"); 

	result=result->next;
	mu_assert(NULL == result, "Result[3] should be NULL");

	return NULL;
}

char *all_tests()
{
	mu_suite_start();
	
	mu_run_test(test_99_plus_99);
	
	return NULL;
}

RUN_TESTS(all_tests)

