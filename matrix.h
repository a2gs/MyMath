#ifndef __MATRIX__
#define __MATRIX__

#define MATRIX_NO   (0)
#define MATRIX_YES  (1)
#define MATRIX_ERRO (0)
#define MATRIX_OK   (1)

int isMatrixSymetric(double *m, unsigned int row, unsigned int col);
int makeTransposeMatrix(double *m, unsigned int row, unsigned int col, double **mt); /* Dynamic allocated, call destroyTransposeMatrix() */
void destroyTransposeMatrix(double *mt);

#endif
