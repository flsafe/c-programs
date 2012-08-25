#include <ctype.h>
#include <assert.h>
#include "debug.h"

int uniq_chars(char *s, int n)
{
	unsigned long int bvec = 0;
	int i = 0;
	char c = 0;

	assert(s != NULL && "Argument can not be null");	

	for(i = 0 ; i < n ; i++){
		c = s[i];
		assert(islower(c) && "Argument must be lowercase alpha characters only");
		
		if (bvec & (1 << (c - 'a'))){
			return 0;	
		} else {
			bvec |= (1 << (c - 'a'));
		}
	}

	return 1;
}
