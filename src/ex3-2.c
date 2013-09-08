#include <stdlib.h>
#include "debug.h"

typedef struct Stack Stack;
struct Stack {
	int size;
	int top;
	int *stack;
};

typedef struct MinStack MinStack;
struct MinStack {
	Stack *data_stack;
	Stack *min_stack;
};

Stack *new_stack(int size){
	Stack *s = NULL;

	check(size > 0, "size must be > 0", NULL);

	s = malloc(sizeof(Stack));
	check_mem(s);
	s->stack = malloc(sizeof(int)*size);
	check_mem(s->stack);
	s->size = size;
	s->top = 0;
	return s;

error:

	free(s);
	if(s) free(s->stack);
	return NULL;
}

int is_empty(Stack *s){
	check(s, "Arg s cannot be null", NULL);

	return s->top <= 0;

error:

	return 1;
}

int peek(Stack *s, int *out_val){
	check(s, "Stack arg cannot be NULL", NULL);
	check(out_val, "out_val arg cannot be NULL", NULL);

	if(is_empty(s)){
		return 0;
	}
	*out_val = s->stack[s->top-1];
	return 1;

error:

	return 0;
}

int push(Stack *s, int elem){
	check(s, "Stack arg can't be NULL", NULL)

	if(s->top >= s->size){
		return 0;
	}
	s->stack[s->top] = elem;
	s->top++;
	return 1;

error:

	return 0;
}

int pop(Stack *s, int *out_elem){
	check(s, "Stack arg can't be null", NULL);

	if(s->top <= 0){
		return 0;
	}
	s->top--;
	*out_elem = s->stack[s->top];
	return 1;

error:

	return 0;
}

/* TODO: Error check operations on min_stack */
int mpush(MinStack *s, int val){
	int cur_min = 0;

	check(s, "Stack arg cannot be nil", NULL);

	if(is_empty(s->min_stack)){
		push(s->min_stack, val);
	} else {
		peek(s->min_stack, &cur_min);
		if(val <= cur_min){
			push(s->min_stack, val);
		}
	}
	return push(s->data_stack, val);

error:

	return 0;
}

int mpop(MinStack *s, int *out_val){
	int pop_val = 0, cur_min = 0,  ignore = 0;

	check(s, "Arg s cannot be null", NULL);
	check(out_val, "Arg out_val cannot be null", NULL);

	if(is_empty(s->min_stack)){
		return 0;
	} else {
		pop(s->data_stack, &pop_val);
		peek(s->min_stack, &cur_min);
		if(pop_val == cur_min){
			pop(s->min_stack, &ignore);
		}
		*out_val = pop_val;
		return 1;
	}

error:

	return 0;
}

int min(MinStack *s, int *out_val){
	check(s, "Arg s cannot be null", NULL);
	check(out_val, "out_val arg cannot be null", NULL);

	if(is_empty(s->min_stack)){
		return 0;
	} else {
		peek(s->min_stack, out_val);
		return 1;
	}

error:

	return 0;
}