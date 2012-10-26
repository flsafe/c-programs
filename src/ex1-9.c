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

int in_list(node *list, int i)
{
	node *curr = NULL;

	for(curr = list ; curr ; curr = curr->next){
		if(i == curr->i){
			return 1;
		}
	}

	return 0;
}

void remove_duplicates_nobuff(node **list)
{
	node *new_list = NULL;
	node *curr = NULL, *next = NULL;

	if(NULL == *list) return;

	curr = *list;
	do{
		next = curr->next;

		if(in_list(next, curr->i)){
			free(curr);	
		}
		else{
			curr->next = new_list;
			new_list = curr;
		}
		curr = next;	
	} while(curr);

	*list = new_list;
}
