/*
 * modularexponentiation.c
 *
 *  This is the modular exponentiation algorithm with a few adjustments 
 *  from the book.
 *
 *  Created on: Sep 21, 2013
 *      Author: Nathan Lane
 *       Class: CSIS-2430
 */

 #include "modularexponentiation.h"
 #include "lists.h"

/**
 * Modular exponentiation algorithm.
 * 
 * where:
 *  - int b base of an exponent
 *  - char * n exponent in binary expansion form
 *  - size_t size of exponent
 *  - int m number to modulate against
 */
int modexp(int b, char * n, size_t size, int m)
{
  char * reversedExponent = reverse(n, size);
  int x = 1;
  int power = b % m;
  int index;
  
  for (index = 0; index < size; index++)
  {
    if (reversedExponent[index] == '1')
	{
	  x = (x * power) % m;
	}
	
	power = (power * power) % m;
  }
  
  return x;
}
