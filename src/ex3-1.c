#include <stdlib.h>

typedef struct Stack Stack;
struct Stack {
	int stack_indexes[3];
	int size;
	int *stack;
};

Stack *make_stack(int size){
	Stack *s = NULL;
	
	if(size < 3) return NULL;
	
	if(!(s = calloc(1, sizeof(Stack)))) return NULL;
	s->stack_indexes[0] = 0;
	s->stack_indexes[1] = size / 3;
	s->stack_indexes[2] = (size / 3) * 2;
	s->size = size;	
	if (!(s->stack = calloc(size, sizeof(int)))) return NULL;
	return s;
}

int stack_push(Stack *s, int stack_num, int e){
	int bottom, top, index;

	if(stack_num < 0 || stack_num > 2 || NULL == s) return 0;
	
	bottom = (s->size / 3) * stack_num;
	top = bottom + (s->size / 3);
	index = s->stack_indexes[stack_num];
	
	printf("index: %d, top: %d\n", index, top);
	
	if(index < top){
		s->stack[index] = e;
		s->stack_indexes[stack_num]++;
		return 1;
	}
	else{
		return 0;
	}
}
