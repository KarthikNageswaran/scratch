/*
 * sieve.c
 *
 *  This is an implementation of one of the sieve algorithms.
 *
 *  Created on: Sep 22, 2013
 *      Author: Nathan Lane
 *       Class: CSIS-2430
 */

#include <stdbool.h>

#include "sieve.h"

long gcd(long first, long second)
{
  long temp = second;
  
  if (second == 0)
  {
    return first;
  }
  
  return gcd(second, (first % second));
}

bool isPrime(long value)
{
  bool result = false;
  
  return result;
}
