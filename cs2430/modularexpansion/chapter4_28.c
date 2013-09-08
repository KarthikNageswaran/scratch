/*
 * chapter4_28.c
 *
 *  Created on: Sep 7, 2013
 *      Author: Nathan Lane
 *       Class: CSIS-2430
 */
 
#include "algorithmone.h"
#include "algorithmfive.h"

#include <stdlib.h>
#include <stdio.h>
 
int main()
{
  const int number = 123;
  const int exponent = 1001;
  const int modulation = 101;
  
  char * expandedValue;
  size_t size = 0;
  
  expandedValue = baseexpansion(exponent, 2, &size);
   
  printf("Result of %i^%i mod %i = %i\n", number, exponent, modulation, modexp(number, expandedValue, size, modulation));
   
  return 0;
}
 