#include <stdlib.h>
#include <assert.h>
#include "debug.h"

#define MAX_INT 1024

typedef struct node node;
struct node{
	int i;
	node *next;
};

void remove_duplicates(node **head)
{
	node *new_list = NULL, *curr = NULL, *next = NULL;
	int seen[MAX_INT] = {0};

	if(NULL == *head) return;

	curr = *head;
	do{
		assert(curr->i < MAX_INT && "Integers must be less than MAX_INT");

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
