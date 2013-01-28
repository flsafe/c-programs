#include <string.h>
#include <ex1-7.c>
#include "minunit.h"

void p_mat(int **mat, int width, int height)
{
	int i = 0, j = 0;

	for(i = 0 ; i < 2*width ; i++){
		printf("---");
	}
	printf("\n");

	for(i = 0 ; i < width ; i++){
		for(j = 0 ; j < height ; j++){
			printf("%d\t", mat[i][j]);	
		}
		printf("\n");
	}

	for(i = 0 ; i < 2*width ; i++){
		printf("---");
	}
	printf("\n");
}

char *test4x4()
{
	int c = 0, width = 4, height = 4;
	int **m= NULL, **me = NULL;

	m = malloc(width * sizeof(int*));
	for(c = 0 ; c < width ; c++){
		m[c] = malloc(height * sizeof(int));
	}

	me = malloc(width * sizeof(int*));
	for(c = 0 ; c < width ; c++){
		me[c] = malloc(height * sizeof(int));
	}

	m[0][0]= 0; m[1][0]= 0 ; m[2][0]= 0; m[3][0]= 0;
	m[0][1]= 0; m[1][1]= 1 ; m[2][1]= 0; m[3][1]= 0;
	m[0][2]= 0; m[1][2]= 0 ; m[2][2]= 0; m[3][2]= 0;
	m[0][3]= 0; m[1][3]= 0 ; m[2][3]= 0; m[3][3]= 0;
	printf("Matrix:\n");
	p_mat(m, width, height);

	me[0][0]= 0; me[1][0]= 1 ; me[2][0]= 0; me[3][0]= 0;
	me[0][1]= 1; me[1][1]= 1 ; me[2][1]= 1; me[3][1]= 1;
	me[0][2]= 0; me[1][2]= 1 ; me[2][2]= 0; me[3][2]= 0;
	me[0][3]= 0; me[1][3]= 1 ; me[2][3]= 0; me[3][3]= 0;
	printf("Expecting:\n");
	p_mat(me, width, height);

	set_rows_and_cols(m, width, height);
	printf("Got:\n");
	p_mat(m, width, height);

	for(c = 0 ; c < width ; c++){
		mu_assert(0 == memcmp(m[c], me[c], sizeof(int) * height),
				  "Failed with matrix of size 4x4");
	}

	return NULL;
}

char *all()
{
	mu_suite_start();

	mu_run_test(test4x4);

	return NULL;
}

RUN_TESTS(all)
