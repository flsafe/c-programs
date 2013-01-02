#include <stdlib.h>
#include <stdio.h>

typedef struct node node;
struct node
{
	int i;
	node *next;
};

node *get_cyc_start(node *h)
{
	node *f = NULL, *s = NULL;

	if(NULL == h) return NULL;

	f = s = h;
	while(f && f->next){
		f = f->next->next;
		s = s->next;
		if(s == f) break;
	}

	/* No cycle */
	if(NULL == f) return NULL;

	s = h;
	while(s != f){
		s = s->next;
		f = f->next;
	}

	return s;
}
