#include <ex1-4.c>
#include "minunit.h"

char *empty_str()
{
	char a[] = "";
	char b[] = "";
	mu_assert(1 == is_anagram(a, sizeof(a) - 1,
				              b, sizeof(b) - 1),
			  "Failed with empty string");

	return NULL;
}

char *str_len_1()
{
	char a[] = "a";
	char b[] = "a";

	mu_assert(1 == is_anagram(a, sizeof(a) - 1,
				              b, sizeof(b) - 1),
			  "Failed with str len 1");

	return NULL;
}

char *anagram()
{
	char a[] = "unnoticed";
	char b[] = "continued";

	mu_assert(1 == is_anagram(a, sizeof(a) - 1,
				              b, sizeof(b) - 1),
			  "Failed with anagram");

	return NULL;
}

char *not_anagram()
{
	char a[] = "unnoticed";
	char b[] = "ravenholm";

	mu_assert(0 == is_anagram(a, sizeof(a) - 1,
				              b, sizeof(b) - 1),
			  "Failed with str that is not an anagram");

	return NULL;

}

char *all_tests()
{
	mu_suite_start();

	mu_run_test(empty_str);
	mu_run_test(str_len_1);
	mu_run_test(anagram);
	mu_run_test(not_anagram);

	return NULL;
}

RUN_TESTS(all_tests)
