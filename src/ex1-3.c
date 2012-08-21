#include <stdlib.h>
#include <assert.h>

void compact_str(char *str, int n)
{
	assert(str != NULL && n >= 0 && "str can not be null, n must be >= 0");
	
	char seen[256] = {0};
	int read = 0;
	int write = 0;

	char c;
	do {
		c = str[read];	
		if(! seen[c]){
			str[write++] = c;	
		}
		seen[c] = 1;
		read++;
	} while(c != '\0' && read <= n); /* We wan't to copy the null char */
}
