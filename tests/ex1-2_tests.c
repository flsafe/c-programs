#include <string.h>
#include <ex1-2.c>
#include "minunit.h"

char *test_small_str()
{
	char str[] = "frank";
	reverse_chars(str, sizeof(str)-1);
	mu_assert(0 == strcmp(str, "knarf"), "Failed to rerverse the string 'Frank'");

	return NULL;
}

char *test_str_len_1()
{
	char f[] = "f";
	reverse_chars(f, sizeof(f)-1);
	mu_assert(0 == strcmp(f, "f"), "Failed to rerverse the string 'f'");

	return NULL;
}

char *test_empty_str()
{
	char empty[] = "";
	reverse_chars(empty, sizeof(empty)-1);
	mu_assert(0 == strcmp(empty, ""), "Failed to rerverse the empty string");

	return NULL;
}

char *all_tests()
{
	mu_suite_start();	

	mu_run_test(test_small_str);
	mu_run_test(test_str_len_1);
	mu_run_test(test_empty_str);

	return NULL;
}

RUN_TESTS(all_tests);
