/*
 * main.c
 *
 * Bacteria growth problem solution.
 *
 *  Created on: Oct 26, 2013
 *      Author: Nathan Lane
 *       Class: CSIS-2430
 */

#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>

int main(int argv, char * argc[])
{
  uint_fast64_t bacteriaColonySize = 2;
  uint_fast64_t minutesElapsed = 0;
  const uint_fast64_t multiplier = 2;
  const uint_fast64_t adder = 20;
  const uint_fast64_t maxColonySizeAtDeath = 1000000; /* One million */
  
  while (bacteriaColonySize < maxColonySizeAtDeath)
  {
    printf("%" PRIu64 " minutes elapsed; Colony size %" PRIu64 "\n", minutesElapsed, bacteriaColonySize);
    
    minutesElapsed = minutesElapsed + adder;
    bacteriaColonySize = bacteriaColonySize * multiplier;
  }
  
  printf("%" PRIu64 " minutes elapsed; Colony size %" PRIu64 "\n", minutesElapsed, bacteriaColonySize);
  printf("Patient is DEAD!\n");
  
  return 0;
}
