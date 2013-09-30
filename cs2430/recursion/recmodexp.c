/*
 * recmodexp.c
 *
 * Recursive modular exponentiation.
 *
 *  Created on: Sep 23, 2013
 *      Author: Nathan Lane
 *       Class: CSIS-2430
 */

#include <stdint.h>

#include "recmodexp.h"

uint64_t square(uint64_t base)
{
  return (base * base);
}

/**
 * Modular exponentiation algorithm.
 * 
 * where:
 *  - uint64_t b base of an exponent
 *  - uint64_t n exponent
 *  - uint64_t m number to modulate against
 */
uint64_t recmodexp(uint64_t b, uint64_t n, uint64_t m)
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
