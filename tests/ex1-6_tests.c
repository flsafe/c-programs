#include <ex1-6.c>
#include "minunit.h"
#include <string.h>

void p_mat(int **mat, int n)
{
	int i = 0, j = 0;

	for(i = 0 ; i < 2*n ; i++){
		printf("---");
	}
	printf("\n");

	for(i = 0 ; i < n ; i++){
		for(j = 0 ; j < n ; j++){
			printf("%d\t", mat[i][j]);	
		}
		printf("\n");
	}

	for(i = 0 ; i < 2*n ; i++){
		printf("---");
	}
	printf("\n");
}

char *n1x1()
{
	int i = 0;
	int n = 0;

	int **mat = malloc(1);
	mat[0] = malloc(1);

	mat[0][0] = 1;

	rotate_90(mat, 1);

	for(i = 0 ; i < n ; i++){
		mu_assert(0 == memcmp(mat[i], mat[i], sizeof(int) * n),
				  "Matrix of size n=1 failed");
	}

	free(mat[0]);
	free(mat);

	return NULL;
}

char *n2x2()
{
	int i = 0;
	int n = 2;

	int **mat = malloc(n);
	for(i = 0 ; i < n ; i++){
		mat[i] = malloc(n);
	}

	mat[0][0] = 1; mat[1][0] = 0;
	mat[0][1] = 0; mat[1][1] = 1;

	p_mat(mat,n);
	rotate_90(mat, n);
	p_mat(mat,n);

	mu_assert(mat[0][0] == 0, "0,0"); mu_assert(mat[1][0] == 1, "1,0");
	mu_assert(mat[0][1] == 1, "0,1"); mu_assert(mat[1][1] == 0, "1,1");

	free(mat[0]);
	free(mat[1]);
	free(mat);

	return NULL;
}

char *n3x3()
{
	int i = 0, n = 3;
	int **mat = NULL, **mat_exp = NULL;

	mat = malloc(n * sizeof(int));
	for(i = 0 ; i < n ; i++){
		mat[i] = malloc(n * sizeof(int));
	}

	mat[0][0] = 1; mat[1][0] = 0; mat[2][0] = 0;
	mat[0][1] = 0; mat[1][1] = 1; mat[2][1] = 0;
	mat[0][2] = 0; mat[1][2] = 0; mat[2][2] = 1;

	mat_exp = malloc(n * sizeof(int));
	for(i = 0 ; i < n ; i++){
		mat_exp[i] = malloc(n * sizeof(int));
	}

	mat_exp[0][0] = 0; mat_exp[1][0] = 0; mat_exp[2][0] = 1;
	mat_exp[0][1] = 0; mat_exp[1][1] = 1; mat_exp[2][1] = 0;
	mat_exp[0][2] = 1; mat_exp[1][2] = 0; mat_exp[2][2] = 0;

	rotate_90(mat,n);

	for(i = 0 ; i < n ; i++){
		mu_assert(0 == memcmp(mat[i], mat_exp[i], sizeof(int)*n), "failed");
	}

	free(mat[0]);
	free(mat[1]);
	free(mat[2]);
	free(mat);

	return NULL;
}

char *n4x4(){
	int i = 0, n = 4;
	int **mat = NULL, **mat_e = NULL;

	mat = malloc(n * sizeof(int));
	for(i = 0 ; i < n ; i++){
		mat[i] = malloc(n * sizeof(int));
	}

	mat[0][0] = 1; mat[1][0] = 0; mat[2][0] = 0; mat[3][0] = 0;
	mat[0][1] = 0; mat[1][1] = 1; mat[2][1] = 0; mat[3][1] = 0;
	mat[0][2] = 0; mat[1][2] = 0; mat[2][2] = 1; mat[3][2] = 0;
	mat[0][3] = 0; mat[1][3] = 0; mat[2][3] = 0; mat[3][3] = 1;

	mat_e = malloc(n * sizeof(int));
	for(i = 0 ; i < n ; i++){
		mat_e[i] = malloc(n * sizeof(int));
	}

	mat_e[0][0] = 0; mat_e[1][0] = 0; mat_e[2][0] = 0; mat_e[3][0] = 1;
	mat_e[0][1] = 0; mat_e[1][1] = 0; mat_e[2][1] = 1; mat_e[3][1] = 0;
	mat_e[0][2] = 0; mat_e[1][2] = 1; mat_e[2][2] = 0; mat_e[3][2] = 0;
	mat_e[0][3] = 1; mat_e[1][3] = 0; mat_e[2][3] = 0; mat_e[3][3] = 0;

	p_mat(mat, n);
	p_mat(mat_e, n);
	rotate_90(mat,n);
	p_mat(mat, n);

	for(i = 0 ; i < n ; i++){
		mu_assert(0 == memcmp(mat[i], mat_e[i], n*sizeof(int)), "failed 4x4");
	}

	free(mat[0]);
	free(mat[1]);
	free(mat[2]);
	free(mat[3]);
	free(mat);

	return NULL;
}

char *all()
{
	mu_suite_start();
	mu_run_test(n1x1);
	mu_run_test(n2x2);
	mu_run_test(n3x3);
	mu_run_test(n4x4);

	return NULL;
}

RUN_TESTS(all)
