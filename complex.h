/* Andre Augusto Giannotti Scota
 * andre.scota@gmail.com
 *
 * My Math Library
 *
 * MIT License
 *
 */

#ifndef __COMPLEX__
#define __COMPLEX__

#define COMPLEX_OK   (0)
#define COMPLEX_ERRO (1)

typedef struct _complexCartesian_t
{
	float real;
	float imaginary;
}complexCartesian_t;

typedef struct _complexPolar_t
{
	float radius;
	float phase;
}complexPolar_t;

int complexCartesianToPolar(complexCartesian_t *c, complexPolar_t *p);
int complexPolarToCartesian(complexPolar_t *p, complexCartesian_t *c);

#endif
