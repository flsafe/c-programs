#include <string.h>
#include <debug.h>
#include <ex1-3.c>
#include "minunit.h"

char *empty_string()
{
	char str[] = "";

	compact_str(str, sizeof(str)-1);
	mu_assert(strcmp(str, "") == 0, "Failed with empty string");

	return NULL;
}

char *no_dups()
{
	char str[] = "abcdefg";

	compact_str(str, sizeof(str)-1);
	mu_assert(strcmp(str, "abcdefg") == 0, "String with no duplicates should not be unmodified");

	return NULL;	
}

char *with_dups()
{
	char str[] = "aabcdeffgdhgg";

	compact_str(str, sizeof(str)-1);
	mu_assert(strcmp(str, "abcdefgh") == 0, "Duplicates where not removed");

	return NULL;
}

char *len_1()
{
	char str[] = "a";
	
	compact_str(str, sizeof(str)-1);
	mu_assert(strcmp(str, "a") == 0, "Failed with str of length 1");

	return NULL;
}

char *all_tests()
{
	mu_suite_start();

	mu_run_test(empty_string);
	mu_run_test(no_dups);
	mu_run_test(with_dups);
	mu_run_test(len_1);

	return NULL;
}

RUN_TESTS(all_tests);
