/*
 * fibonacci.c
 *
 * Fibonacci methods.
 *
 *  Created on: Sep 23, 2013
 *      Author: Nathan Lane
 *       Class: CSIS-2430
 */

#include <stdint.h>

#include "fibonacci.h" 
 
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
 
uint64_t iterative_fib(uint64_t n)
{
  uint64_t x = 0;
  uint64_t y = 1;
  uint64_t count;
  uint64_t z;
  
  if (n == 0)
  {
    return 0;
  }
  
  for (count = 1; count < n; count++)
  {
    z = (x + y);
    x = y;
    y = z;
  }
  
  return y;
}
