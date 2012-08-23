#include <stdlib.h>
#include <assert.h>
#include <debug.h>

/*
 * Replace spaces with %20
 */
char *enc_sp(char *s, int n)
{
	assert(NULL != s && n >= 0 && "Invalid arguments");

	int i = 0, sp = 0;
	for(i = 0 ; i < n ; i++){
		if(s[i] == ' '){
			sp++;	
		}
	}

	char *new_s = calloc((n + (2 * sp)) + 1, sizeof(char));
	check_mem(new_s);
	
	int read = 0, write = 0;
	char c;
	do {
		c = s[read++];

		if (c == ' '){
			new_s[write++] = '%';
			new_s[write++] = '2';
			new_s[write++] = '0';
		} else {
			new_s[write++] = c;
		}
	} while (c != '\0' && read <= n);

	return new_s;

error:

	free(new_s);
	return NULL;
}
