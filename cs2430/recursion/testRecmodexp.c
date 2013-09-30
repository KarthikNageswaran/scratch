/*
 * testRecmodexp.h
 *
 * Test of the recursive modular exponentiation.
 *
 *  Created on: Sep 23, 2013
 *      Author: Nathan Lane
 *       Class: CSIS-2430
 */

#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>

#include "recmodexp.h"

int main(int argv, char * argc[])
{
  uint64_t base;
  uint64_t exponent;
  uint64_t modVal;
  char * end;
  clock_t startTime;
  clock_t endTime;
  
  if (argv != 4)
  {
    printf("usage: %s <base> <exponent> <modulus>", argc[0]);
    
    return 1;
  }

  base = strtoull(argc[1], &end, 10);
  exponent = strtoull(argc[2], &end, 10);
  modVal = strtoull(argc[3], &end, 10);

  startTime = clock();
  
  printf("Result of %" PRIu64 "^%" PRIu64 " mod %" PRIu64 " = %" PRIu64 "\n", base, exponent, modVal, recmodexp(base, exponent, modVal));
  
  endTime = clock();
  
  printf("Total time to calculate result of %" PRIu64 "^%" PRIu64 " mod %" PRIu64 ": %f", base, exponent, modVal, (double) ((endTime-startTime) / CLOCKS_PER_SEC));
  
  return 0;
}