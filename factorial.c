/* Andre Augusto Giannotti Scota
 * andre.scota@gmail.com
 *
 * My Math Library
 *
 * MIT License
 *
 */

#include "factorial.h"

inline unsigned long long DefinedFactorial(unsigned long x, unsigned long y)
{
	unsigned long long ret = 1;

	for(ret = 1; x > y; ret *= x, x--);

	return(ret);
}
