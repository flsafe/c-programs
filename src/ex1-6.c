#include <stdlib.h>
#include <assert.h>

void rotate_90(int **mat, int n)
{
	int ax,ay, bx,by, cx,cy, dx,dy;
	int acpy, bcpy, ccpy, dcpy;
	int i, j, offset;

	assert(mat != NULL && n >= 0 && "Invalid args");

	ax = 0; ay = 0;
	bx = 0; by = n-1;
	cx = n-1; cy = n-1;
	dx = n-1; dy = 0;

	for(i = 0 ; i < n/2 ; i++){
		offset = 0;
		for(j = 0 ; j < n-1 ; j++){
			acpy = mat[ax][ay+offset];
			bcpy = mat[bx+offset][by];
			ccpy = mat[cx][cy-offset];
			dcpy = mat[dx-offset][dy];

			mat[ax][ay+offset] = dcpy;
			mat[bx+offset][by] = acpy;
			mat[cx][cy-offset] = bcpy;
			mat[dx-offset][dy] = ccpy;

			offset++;
		}
		ax += 1; ay += 1;
		bx += 1; by -= 1;
		cx -= 1; by -= 1;
		dx -=1 ; dy += 1;
	}
}
