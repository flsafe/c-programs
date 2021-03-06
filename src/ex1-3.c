#include <stdlib.h>
#include <assert.h>

void compact_str(char *str, int n)
{
	char seen[256] = {0};
	int read = 0;
	int write = 0;
	unsigned char c;

	assert(str != NULL && n >= 0 && "str can not be null, n must be >= 0");

	do {
		c = str[read++];	

		if(! seen[c]){
			str[write++] = c;	
		}

		seen[c] = 1;
	} while(c != '\0' && read <= n); /* We wan't to copy the null char */
}
