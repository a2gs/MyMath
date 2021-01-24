/* Andre Augusto Giannotti Scota
 * andre.scota@gmail.com
 *
 * My Math Library
 *
 * MIT License
 *
 */

#include <stdlib.h>
#include <string.h>
#include "matrix.h"

static inline unsigned int offset(unsigned int l, unsigned int c, unsigned int cTot)
{
	return((l * cTot) + c);
}

int isMatrixSymetric(double *m, unsigned int row, unsigned int col)
{
	unsigned int l = 0, c = 0;

	if((row != col) || (row < 1)) return(MATRIX_NO);

	for(l = 1; l != row; l++){
		for(c = 0; c != l; c++){
			if(m[offset(l, c, row)] != m[offset(c, l, row)]) return(MATRIX_NO);
		}
	}
	return(MATRIX_YES);
}

int makeTransposeMatrix(double *m, unsigned int row, unsigned int col, double **mt)
{
	size_t mtSz = 0;
	unsigned int l = 0, c = 0;

	mtSz = sizeof(double) * row * col;

	*mt = malloc(mtSz);
	if(*mt == NULL)
		return(MATRIX_ERRO);

	memset(*mt, 0, mtSz);

	for(l = 0; l < row; l++){
		for(c = 0; c < col; c++){
			mt[offset(c, l, row)] = &m[offset(l, c, col)];
		}
	}

	return(MATRIX_OK);
}

void destroyTransposeMatrix(double *mt)
{
	free(mt);
}
