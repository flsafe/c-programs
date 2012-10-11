#include "minunit.h"
#include <ex1-8.c>

char *test_rotation()
{
	int r = 0;
	char a[] = "Frank";
	char b[] = "rankF";

	r = is_rotation(a, sizeof(a) - 1, b, sizeof(b) - 1);
	mu_assert(r, "Test with rotation failed");

	return NULL;
}

char *test_not_rotation()
{
	int r = 0;
	char a[] = "Frank";
	char b[] = "rankA";

	r = is_rotation(a, sizeof(a) - 1, b, sizeof(b) - 1);
	mu_assert(0 == r, "Test no rotation failed");

	return NULL;
}

char *test_with_empty_str()
{
	int r = 0;
	char a[] = "";
	char b[] = "rankA";

	r = is_rotation(a, sizeof(a) - 1 , b, sizeof(b) - 1);
	mu_assert(0 == r, "Test with empty string failed");

	return NULL;
}

char *test_with_empty_b()
{
	int r = 0;
	char a[] = "Frank";
	char b[] = "";

	r = is_rotation(a, sizeof(a) - 1, b, sizeof(b) - 1);
	mu_assert(0 == r, "Test with empty b string failed");

	return NULL;
}

char *test_with_str_len_1()
{
	int r = 0;
	char a[] = "f";
	char b[] = "f";

	r = is_rotation(a, sizeof(a) - 1, b, sizeof(b) - 1);
	mu_assert(1 == r, "Test with string len 1 failed");

	return NULL;
}

char *test_with_uneven()
{
	int r = 0;
	char a[] = "frank";
	char b[] = "fra";

	r = is_rotation(a, sizeof(a) - 1, b, sizeof(b) - 1);
	mu_assert(0 == r, "Test with string len 1 failed");

	return NULL;
}

char *all()
{
	mu_suite_start();	

	mu_run_test(test_rotation);
	mu_run_test(test_not_rotation);
	mu_run_test(test_with_empty_str);
	mu_run_test(test_with_empty_b);
	mu_run_test(test_with_str_len_1);
	mu_run_test(test_with_uneven);

	return NULL;
}

RUN_TESTS(all)
