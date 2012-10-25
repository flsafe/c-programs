#include <stdlib.h>
#include "debug.h"

typedef struct node node;
struct node{
	int i;
	node *next;
};

void remove_duplicates(node **head)
{
	node *new_list = NULL, *curr = NULL, *next = NULL;
	int seen[1024] = {0};

	if(NULL == *head) return;

	curr = *head;
	do{
		next = curr->next;

		if(0 == seen[curr->i]){
			curr->next = new_list;
			new_list = curr;
			seen[curr->i] = 1;
		} 
		else {
			free(curr);	
		}
		curr = next;
	} while (curr);

	*head = new_list;
}
