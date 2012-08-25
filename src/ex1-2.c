#include <stdlib.h>
#include <assert.h>

void reverse_chars(char *str, int n)
{
	int first = 0;
	int temp;
	int last = n - 1;

	assert(NULL != str && "Argument str can not be null");
	assert(n > -1 && "Argument n must be greater than 0");

	while(first < last){
		temp = str[first];
		str[first] = str[last];
		str[last] = temp;
		
		first++ ; last--;
	}
}
