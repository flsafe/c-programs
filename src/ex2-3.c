#include <stdlib.h>

typedef struct node node;
struct node{
	int i;
	node *next;
};

void remove_mid_node(node *mid)
{
	node *curr = NULL;
	int midval = 0;

	if(NULL == mid || NULL == mid->next){
		return;
	}

	midval = mid->i;
	curr = mid;

	while(curr->next->next){
		curr->i = curr->next->i;
		curr = curr->next;
	}
	curr->i = curr->next->i;

	curr->next->i = midval;
	free(curr->next);
	curr->next = NULL;
}

