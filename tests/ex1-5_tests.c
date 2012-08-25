#include <string.h>
#include <ex1-5.c>
#include "minunit.h"

char *empty()
{
	char s[] = "";
	char *r = enc_sp(s, sizeof(s)-1);

	mu_assert(r, "Returned NULL on empty string");
	mu_assert(0 == strcmp(r, s), "Failed with empty string");

	return NULL;
}

char *no_sp()
{
	char s[] = "abcdefg";

	char *r = enc_sp(s, sizeof(s)-1);
	
	mu_assert(r, "Returned NULL");
	mu_assert(0 == strcmp(s,r), "Failed with no spaces");

	return NULL;
}

char *one_sp()
{
	char s[] = " ";

	char *r = enc_sp(s, sizeof(s)-1);

	mu_assert(r, "Returned NULL");
	mu_assert(0 == strcmp(r, "%20"), "Failed with one space");

	return NULL;
}

char *many_sp()
{
	char s[] = " a  b c ";

	char *r = enc_sp(s, sizeof(s)-1);
	
	mu_assert(r, "Returned NULL");
	mu_assert(0 == strcmp(r, "%20a%20%20b%20c%20"), "Failed with many spaces");

	return NULL;
}

char *all()
{
	mu_suite_start();

	mu_run_test(empty);
	mu_run_test(no_sp);
	mu_run_test(one_sp);
	mu_run_test(many_sp);

	return NULL;
}

RUN_TESTS(all)
