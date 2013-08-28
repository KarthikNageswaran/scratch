/*
 * printarrays.c
 *
 *  Created on: Aug 28, 2013
 *      Author: Nathan Lane
 *       Class: CSIS-2430
 */

#include <stdio.h>

#include "printarrays.h"

void printarray(const int array[], const unsigned int numElements)
{
  int index;

  if (numElements == 0)
  {
    return;
  }

  for (index = 0; index < numElements; index++)
  {
    if (index > 0)
    {
      printf(", ");
    }

    printf("%d", array[index]);
  }

  printf("\n");
}

