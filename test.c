#include <stdio.h>
#include <stdlib.h>

#include "trigonometry.h"
#include "matrix.h"

static inline unsigned int os(unsigned int l, unsigned int c, unsigned int cTot)
{
	return((l * cTot) + c);
}

int main(int argc, char *argv[])
{
	double m1[5][5] = {
	                   {1.0, 2.0, 3.0, 4.0, 5.0},
	                   {2.0, 1.0, 3.0, 4.0, 5.0},
	                   {3.0, 3.0, 1.0, 4.0, 5.0},
	                   {4.0, 4.0, 4.0, 1.0, 5.0},
	                   {5.0, 5.0, 5.0, 5.0, 1.0},
	                  };
	double m2[2][5] = {
	                   {1.0, 2.0, 3.0, 4.0, 5.0},
	                   {4.0, 5.0, 6.0, 7.0, 8.0}
	                  };
	double *mt2 = NULL;
	double *mt2Ret = NULL;

	printf("[%f]\n", SinAplusB(DegreeToRad(30.0), DegreeToRad(60.0)));
	printf("[%f]\n", SinAminusB(DegreeToRad(30.0), DegreeToRad(60.0)));
	printf("[%f]\n", CosAplusB(DegreeToRad (30.0), DegreeToRad(60.0)));
	printf("[%f]\n", CosAminusB(DegreeToRad(30.0), DegreeToRad(60.0)));
	printf("[%f]\n", TanAplusB(DegreeToRad (30.0), DegreeToRad(60.0)));
	printf("[%f]\n", TanAminusB(DegreeToRad(30.0), DegreeToRad(60.0)));
	printf("[%f]\n", Sin2A(DegreeToRad(30.0)));
	printf("[%f]\n", Cos2A(DegreeToRad(30.0)));
	printf("[%f]\n", Tan2A(DegreeToRad(30.0)));
	printf("[%f]\n", SinAdiv2(DegreeToRad(30.0)));
	printf("[%f]\n", CosAdiv2(DegreeToRad(30.0)));
	printf("[%f]\n", SinAplusSinB(DegreeToRad(30.0), DegreeToRad(60.0)));
	printf("[%f]\n", SinAminusSinB(DegreeToRad(30.0), DegreeToRad(60.0)));
	printf("[%f]\n", CosAplusCosB(DegreeToRad(30.0), DegreeToRad(60.0)));
	printf("[%f]\n", CosAminusCosB(DegreeToRad(30.0), DegreeToRad(60.0)));

	printf("\n");

	printf("m1 = [%1.1f %1.1f %1.1f %1.1f %1.1f]\n" \
	       "     [%1.1f %1.1f %1.1f %1.1f %1.1f]\n" \
	       "     [%1.1f %1.1f %1.1f %1.1f %1.1f]\n" \
	       "     [%1.1f %1.1f %1.1f %1.1f %1.1f]\n" \
	       "     [%1.1f %1.1f %1.1f %1.1f %1.1f]\n",
	       m1[0][0], m1[0][1], m1[0][2], m1[0][3], m1[0][4],
	       m1[1][0], m1[1][1], m1[1][2], m1[1][3], m1[1][4],
	       m1[2][0], m1[2][1], m1[2][2], m1[2][3], m1[2][4],
	       m1[3][0], m1[3][1], m1[3][2], m1[3][3], m1[3][4],
	       m1[4][0], m1[4][1], m1[4][2], m1[4][3], m1[4][4]);

	printf("m1 is symetric? [%s]\n", (isMatrixSymetric((double *)&m1, 5, 5) == MATRIX_NO ? "NO" : "YES"));

	printf("\n");

	printf("m2 = [%1.1f %1.1f %1.1f %1.1f %1.1f]\n" \
	       "     [%1.1f %1.1f %1.1f %1.1f %1.1f]\n",
	       m2[0][0], m2[0][1], m2[0][2], m2[0][3], m2[0][4],
	       m2[1][0], m2[1][1], m2[1][2], m2[1][3], m2[1][4]);

	mt2 = &m2[0][0];

	if(makeTransposeMatrix(mt2, 2, 5, &mt2Ret) == MATRIX_ERRO)
		printf("Erro making a transpose matrix.\n");
	else{
#define MATOFFSET(__matoffset__) (sizeof(double) * __matoffset__)
		printf("mt1 = [%1.1f %1.1f]\n" \
		       "      [%1.1f %1.1f]\n" \
		       "      [%1.1f %1.1f]\n" \
		       "      [%1.1f %1.1f]\n" \
		       "      [%1.1f %1.1f]\n",
	       (mt2Ret+MATOFFSET(0))[0], (mt2Ret+MATOFFSET(1))[0],
			 (mt2Ret+MATOFFSET(0))[1], (mt2Ret+MATOFFSET(1))[1],
	       (mt2Ret+MATOFFSET(0))[2], (mt2Ret+MATOFFSET(1))[2],
			 (mt2Ret+MATOFFSET(0))[3], (mt2Ret+MATOFFSET(1))[3],
	       (mt2Ret+MATOFFSET(0))[4], (mt2Ret+MATOFFSET(1))[4]);

		/*destroyTransposeMatrix(mt);*/
	}

	return(0);
}
