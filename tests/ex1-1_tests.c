#include "minunit.h"
#include "ex1-1.c"

char *test_short_uniq_str()
{
	char unique[] = "abcdefg"; 
	int unique_len = sizeof(unique) - 1;
	mu_assert(1 == uniq_chars(unique, unique_len), "uniq_chars failed with unique input");

	return NULL;
}

char *test_short_non_uniq_str()
{
	char not_unique[] = "abcdeefgh"; 
	int not_unique_len = sizeof(not_unique) - 1;
	mu_assert(0 == uniq_chars(not_unique, not_unique_len), "uniq_chars failed with unique input");

	return NULL;
}

char *test_empty_str()
{
	char empty_str[] = ""; 
	int empty_str_len = sizeof(empty_str) - 1;
	mu_assert(1 == uniq_chars(empty_str, empty_str_len), "uniq_chars failed with unique input");

	return NULL;
}

char *all_tests(){
	mu_suite_start();

	mu_run_test(test_short_uniq_str);
	mu_run_test(test_short_non_uniq_str);
	mu_run_test(test_empty_str);

	return NULL;
}

RUN_TESTS(all_tests);
