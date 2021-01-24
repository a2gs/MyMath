#include <math.h>

#ifndef M_PI
	#define M_PI 3.14159265358979323846
#endif

/*static inline*/ double DegreeToRad(double d)
{
	return(d * M_PI / 180);
}

/*static inline*/ double RadToDegree(double r)
{
	return(r * 180 / M_PI);
}

/*static inline*/ double SinAplusB(double a, double b)
{
	return((sin(a) * cos(b)) + (sin(b) * cos(a)));
}

/*static inline*/ double SinAminusB(double a, double b)
{
	return((sin(a) * cos(b)) - (sin(b) * cos(a)));
}

/*static inline*/ double CosAplusB(double a, double b)
{
	return((cos(a) * cos(b)) - (sin(b) * sin(a)));
}

/*static inline*/ double CosAminusB(double a, double b)
{
	return((cos(a) * cos(b)) + (sin(b) * sin(a)));
}

/*static inline*/ double TanAplusB(double a, double b)
{
	return((tan(a) + tan(b)) / (1.0 - (tan(a) * tan(b))));
}

/*static inline*/ double TanAminusB(double a, double b)
{
	return((tan(a) - tan(b)) / (1.0 + (tan(a) * tan(b))));
}

/*static inline*/ double Sin2A(double a)
{
	return(2.0 * sin(a) * cos(a));
}

/*static inline*/ double Cos2A(double a)
{
	return(1.0 - ( 2 * pow(sin(a), 2.0)));
}

/*static inline*/ double Tan2A(double a)
{
	return((2.0 * tan(a)) / (1 - pow(tan(a), 2.0)));
}

/*static inline*/ double SinAdiv2(double a) /* + and - */
{
	return(sqrt((1.0 - cos(a)) / 2.0));
}

/*static inline*/ double CosAdiv2(double a) /* + and - */
{
	return(sqrt((1.0 + cos(a)) / 2.0));
}

/*static inline*/ double SinAplusSinB(double a, double b)
{
	return(2.0 * sin((a + b) / 2) * cos((a - b) / 2));
}

/*static inline*/ double SinAminusSinB(double a, double b)
{
	return(2.0 * cos((a + b) / 2) * sin((a - b) / 2));
}

/*static inline*/ double CosAplusCosB(double a, double b)
{
	return(2.0 * cos((a + b) / 2) * cos((a - b) / 2));
}

/*static inline*/ double CosAminusCosB(double a, double b)
{
	return(-2.0 * sin((a + b) / 2) * sin((a - b) / 2));
}
