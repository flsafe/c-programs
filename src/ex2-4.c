#include <stdlib.h>

typedef struct node {
	int i;
	struct node *next;
} node;

int append(node **h, int i)
{
	node *cur = NULL;
	
	node *new = malloc(sizeof(node));
	if(NULL == new) return 0;
	new->i = i;
	new->next = NULL;
	
	if(NULL == *h){
		*h = new;
		return 1;
	}
	else{
		for(cur = *h ; cur->next ; cur = cur->next){
			/* Nothing, move to end of list */	
		}
		cur->next = new;
		return 1;
	}
}

void do_sum_lists(node *h1, node *h2, node **out_result, int carry)
{
	int sum = 0;
	
	if(NULL == h1 && NULL == h2){
		if(carry) append(out_result, carry);
		return;
	}
	
	sum = (NULL == h1 ? 0 : h1->i) + (NULL == h2 ? 0 : h2->i) + carry;
	if(sum >= 10){
		append(out_result, sum-10);
		do_sum_lists((NULL == h1 ? NULL : h1->next), 
				     (NULL == h2 ? NULL : h2->next), out_result,  1);
	}
	else{
		append(out_result, sum);
		do_sum_lists((NULL == h1 ? NULL : h1->next), 
					 (NULL == h2 ? NULL : h2->next), out_result, 0);
	}
}

node *sum_lists(node *h1, node *h2)
{
	node *result = NULL;
	if(NULL == h1 && NULL == h2){
		return NULL;
	}
	
	do_sum_lists(h1, h2, &result, 0);
	
	return result;
}
