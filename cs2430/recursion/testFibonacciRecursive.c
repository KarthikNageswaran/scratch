/*
 * testFibonacciIterative.h
 *
 * Testing Fibonacci method - iterative version.
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

#include "fibonacciRecursive.h"

int main(int argv, char * argc[])
{
  uint64_t index;
  char * end;
  clock_t startTime;
  clock_t endTime;
  
  if (argv != 2)
  {
    printf("usage: %s <number-of-values>", argc[0]);
    
    return 1;
  }
  
  index = strtoull(argc[1], &end, 10);

  startTime = clock();
  
  printf("%" PRIu64 " ", recursive_fib(index));
  
  endTime = clock();
  
  printf("Total time to calculate %" PRIu64 "(th) Fibonacci element: %f\n", index, (double) ((endTime-startTime) / CLOCKS_PER_SEC));
  
  return 0;
}
