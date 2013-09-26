/*
 * recmodexp.c
 *
 * Recursive modular exponentiation.
 *
 *  Created on: Sep 23, 2013
 *      Author: Nathan Lane
 *       Class: CSIS-2430
 */

#include "recmodexp.h"

int square(int base)
{
  return (base * base);
}

/**
 * Modular exponentiation algorithm.
 * 
 * where:
 *  - int b base of an exponent
 *  - int n exponent
 *  - int m number to modulate against
 */
int recmodexp(int b, int n, int m)
{
  if (n == 0)
  {
    return 1;
  }
  else if (n % 2 == 0)
  {
    return (square(recmodexp(b, (n / 2), m)) % m);
  }
  else
  {
    return (((square(recmodexp(b, (n / 2), m)) % m) * (b % m)) % m);
  }
}
