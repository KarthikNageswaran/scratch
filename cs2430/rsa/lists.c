/*
 * lists.c
 *
 *  Provides some list operations.
 *
 *  Created on: Sep 7, 2013
 *      Author: Nathan Lane
 *       Class: CSIS-2430
 */

#include "lists.h"
 
 /**
 * Reverses a string.
 */
char * reverse(const char * original, size_t size)
{
  static char * result;
  int originalIndex;
  int index;
  
  result = calloc(size, sizeof(char));
  
  for (index = 0, originalIndex = (size - 1); originalIndex >= 0; index++, originalIndex--)
  {
    result[index] = original[originalIndex];
  }
  
  return result;
}
