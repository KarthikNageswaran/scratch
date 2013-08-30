/*
 * lists.c
 *
 *  Created on: Aug 28, 2013
 *      Author: Nathan Lane
 *       Class: CSIS-2430
 */

#include <stdio.h>

#include "lists.h"
#include "printarrays.h"

/**
 * Creates a deep copy of another array.
 */
int * makeDeepCopyOfArray(const int * original, const size_t size)
{
  int * list;
  int index;

  list = calloc(size, sizeof(int));
  
  for (index = 0; index < size; index++)
  {
    list[index] = original[index];
  }
  
  return list;
}

