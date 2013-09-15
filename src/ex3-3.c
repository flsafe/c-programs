#include <stdlib.h>
#include "debug.h"

#define NUM(arr) (sizeof(arr)/sizeof(arr[0]))

typedef struct node node;
struct node {
	int val;
	node *next;
};

typedef struct multistack multistack;
struct multistack {
	int size;
	int per_stack_size;
	node *plates[3];
};

int s_push(node **stack, int val){
	node *n = NULL;

	check(stack, "Arg pointer to stack must not be null", NULL);

	n = malloc(sizeof(node));
	check_mem(n);
	n->val = val;
	n->next = *stack;
	*stack = n;
	return 1;

error:

	if(n) free(n);
	return 0;
}

int s_pop(node **stack, int *out_val){
	node *prev_head = NULL;

	check(stack, "Arg pointer to stack can't be null", NULL);
	check(out_val, "Arg out_val can't be null", NULL);

	if(*stack == NULL){
		return 0;
	}

	prev_head = (*stack);
	*stack = prev_head->next;
	*out_val = prev_head->val;
	free(prev_head);
	return 1;

error:

	return 0;
}

multistack *new_multistack(int per_stack_size){
	multistack *stack = NULL;
	int i = 0;

	stack = malloc(sizeof(multistack));
	check_mem(stack);
	stack->size = 0;
	stack->per_stack_size = per_stack_size;
	for(i = 0 ; i < NUM(stack->plates) ; i++){
		stack->plates[i] = NULL;
	}
	return stack;

error:

	if(stack) free(stack);
	return NULL;
}

int push_multistack(multistack *stack, int val){
	node **plate_stack = NULL;
	int stack_index = 0;

	check(stack, "Arg stack can't be null", NULL);

	stack_index = stack->size/stack->per_stack_size;
	plate_stack = &stack->plates[stack_index];
	if(s_push(plate_stack, val)) {
		stack->size++;
		return 1;
	} else {
		return 0;
	}

error:

	return 0;
}

int pop_multistack(multistack *stack, int *out_val){
	int stack_index = 0;
	node **plate_stack = NULL;

	check(stack, "Arg stack can't be null", NULL);
	check(out_val, "Arg out_val can't be null", NULL);

	if(stack->size == 0) return 0;
	stack_index = ((stack->size-1)/stack->per_stack_size);
	plate_stack = &stack->plates[stack_index];

	if(s_pop(plate_stack, out_val)){
		stack->size--;
		return 1;
	} else {
		return 0;
	}

error:

	return 0;
}