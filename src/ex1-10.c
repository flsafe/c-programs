#include "debug.h"

typedef struct node node;
struct node{
	int i;
	node *next;
};

node *get_nth_to_last(node *list, int nth)
{

	node *pahead = NULL, *curr = NULL;
	int moved = 0;

	check(nth > 0, "Nth must be > 0", NULL);
	check(list, "list must not be null", NULL);

	for(pahead = list ; pahead && moved < nth - 1; pahead = pahead->next){
		moved++;	
	}

	if(NULL == pahead) return NULL;

	for(curr = list ; pahead->next ; pahead = pahead->next, curr = curr->next){
		/* move both forward */		
	}

	return curr;

error:

	return NULL;
}
