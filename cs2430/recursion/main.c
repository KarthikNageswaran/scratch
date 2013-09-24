/*
 * main.h
 *
 * Fibonacci methods.
 *
 *  Created on: Sep 23, 2013
 *      Author: Nathan Lane
 *       Class: CSIS-2430
 */

#include <stdio.h>
#include <time.h>
#include <stdint.h>

#include "fibonacci.h"

void testIterativeFibonacci(uint64_t numItems)
{
  uint64_t count;
  clock_t startTime;
  clock_t endTime;
  
  printf("Iterative fibonacci: ");
  
  for (count = 1; count <= numItems; count++)
  {
    startTime = clock();
    
    printf("%li ", iterative_fib(count));
    
    endTime = clock();
    
    printf(" - Time: %f\n", (double) ((endTime-startTime) / CLOCKS_PER_SEC));
  }
  
  printf("\n");
}

void testRecursiveFibonacci(uint64_t numItems)
{
  uint64_t count;
  clock_t startTime;
  clock_t endTime;
  
  printf("Recursive fibonacci: ");
  
  for (count = 1; count <= numItems; count++)
  {
    startTime = clock();
    
    printf("%li ", recursive_fib(count));
    
    endTime = clock();
    
    printf(" - Time: %f\n", (double) ((endTime-startTime) / CLOCKS_PER_SEC));
  }
  
  printf("\n\n");
}

int main(int argv, char * argc[])
{
  uint64_t numItems;
  char * end;
  
  if (argv != 2)
  {
    printf("usage: %s number-of-fibonacci-items\n\n", argc[0]);
    
    return 1;
  }
  else if (atoi(argc[1]) < 0)
  {
    printf("number-of-fibonacci-items cannot be negative.\n\n");
    
    return 2;
  }
  
  printf("CLOCKS_PER_SEC: %li\n", CLOCKS_PER_SEC);
  
  numItems = strtoull(argc[1], &end, 0);
  
  testIterativeFibonacci(numItems);
  testRecursiveFibonacci(numItems);
  
  return 0;
}
