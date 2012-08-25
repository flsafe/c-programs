#include <stdlib.h>
#include <assert.h>
#include "debug.h"

int sort_fn(const void *a, const void *b)
{
	return (*(char*)a) - (*(char*)b);
}

int is_anagram(char *a, int a_len, char *b, int b_len)
{
	char *a_cpy = NULL, *b_cpy = NULL;
	int is_anagram = 0;

	assert(NULL != a && a_len >= 0 && NULL != b && b_len >= 0 && "Invalid args");

	if(a_len != b_len) return 0;

	a_cpy = malloc((a_len + 1) * sizeof(char));
	check_mem(a_cpy);

	b_cpy = malloc((b_len + 1) * sizeof(char));
	check_mem(b_cpy);

	strncpy(a_cpy, a, a_len);
	strncpy(b_cpy, b, b_len);

	qsort(a_cpy, a_len, sizeof(char), sort_fn);
	qsort(b_cpy, b_len, sizeof(char), sort_fn);

	is_anagram = (0 == strncmp(a_cpy, b_cpy, a_len));

	free(a_cpy);
	free(b_cpy);

	return is_anagram;
	
error:

	free(a_cpy);
	free(b_cpy);

	return -1;
}
