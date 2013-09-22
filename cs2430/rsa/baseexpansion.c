/*
 * baseexpansion.c
 *
 *  This is the base expansion algorithm with a few adjustments 
 *  from the book.
 *
 *  Created on: Sep 21, 2013
 *      Author: Nathan Lane
 *       Class: CSIS-2430
 */

#include "baseexpansion.h"
#include "lists.h"

#include <stdlib.h>
#include <stdio.h>

#define INT_BASE_EXPANSION_SIZE 256

/**
 * Base expansion algorithm - assumes you want to convert from int.
 * 
 * where:
 *  - int original integer
 *  - int base to expand to
 *  - size_t pointer to size of result
 */
char * baseexpansion(int n, int base, size_t * size)
{
  const char * POSSIBLE_VALUES = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  static char * result;

  int q = n;
  int index = 0;
  
  result = calloc(INT_BASE_EXPANSION_SIZE, sizeof(char));

  if (base <= 1)
  {
    snprintf(result, INT_BASE_EXPANSION_SIZE, "%i", n);
  }
  else
  {
    while (q != 0)
	{	  
	  result[index] = POSSIBLE_VALUES[(q % base)];
	  
	  q = (div(q, base)).quot;
	  
	  index++;
	}
  }
  
  (* size) = index;
  
  return reverse(result, index);
}

/**
 * Base expansion algorithm - assumes you want to convert from long.
 * 
 * where:
 *  - long original integer
 *  - int base to expand to
 *  - size_t pointer to size of result
 */
char * baseexpansion(long n, int b, size_t *)
{
  const char * POSSIBLE_VALUES = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  static char * result;

  int q = n;
  int index = 0;
  
  result = calloc(INT_BASE_EXPANSION_SIZE, sizeof(char));

  if (base <= 1)
  {
    snprintf(result, INT_BASE_EXPANSION_SIZE, "%i", n);
  }
  else
  {
    while (q != 0)
	{	  
	  result[index] = POSSIBLE_VALUES[(q % base)];
	  
	  q = (div(q, base)).quot;
	  
	  index++;
	}
  }
  
  (* size) = index;
  
  return reverse(result, index);
}
