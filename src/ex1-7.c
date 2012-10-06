#include <stdlib.h>
#include "debug.h"

int set_rows_and_cols(int **mat, int width, int height)
{
	int *set_rows = NULL;
	int *set_cols = NULL;
	int r = 0, c = 0;

	check(mat, "mat arguments cannot be null", NULL);
	check(width >= 0, "width must be non-negative", NULL);
	check(height >= 0, "height must be non-negative", NULL);

	set_cols = calloc(width, sizeof(int));
	check_mem(set_cols);

	set_rows = calloc(height, sizeof(int));
	check_mem(set_rows);

	for(c = 0 ; c < width ; c++){
		for(r = 0 ; r < height ; r++){
			if (1 == mat[c][r]){
				set_cols[c] = 1;
				set_rows[r] = 1;
			}
		}	
	}

	for(c = 0 ; c < width ; c++){
		for(r = 0 ; r < height ; r++){
			if(set_cols[c] || set_rows[r]){
				mat[c][r] = 1;	
			}	
		}
	}

	free(set_rows);
	free(set_cols);

	return 1;

error:

	if(set_rows) free(set_rows);
	if(set_cols) free(set_cols);

	return 0;
}
