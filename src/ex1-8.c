#include <stdlib.h>
#include <string.h>
#include "debug.h"

/*
 * Returns 1 if b is a rotation of a
 */
int is_rotation(char *a, int na, char *b, int nb)
{
	char *found = NULL;
	char *double_a = NULL;

	check(a, "Arg a cannot be null", NULL);
	check(b, "Arg a cannot be null", NULL);
	check(na >= 0, "Arg na cannot be < 0", NULL);
	check(nb >= 0, "Arg nb cannot be < 0", NULL);

	if (na != nb) return 0;

	double_a = calloc((na * 2) + 1, sizeof(char));
	check_mem(double_a);

	memcpy(double_a, a, na);
	memcpy(double_a + na, a, na);

	found = strstr(double_a, b); 

	free(double_a);

	return found != NULL;

error:

	if(double_a) free(a);

	return 0;
}
