/*
 * fibonacciRecursive.c
 *
 * Fibonacci - recursive method.
 *
 *  Created on: Sep 23, 2013
 *      Author: Nathan Lane
 *       Class: CSIS-2430
 */

#include "fibonacciRecursive.h"
 
#include <stdint.h>

uint64_t recursive_fib(uint64_t n)
{
  if (n == 0)
  {
    return 0;
  }
  else if (n == 1)
  {
    return 1;
  }

  return recursive_fib(n - 1) + recursive_fib(n - 2);
}
