/*
 * nathansort.c
 *
 *  Created on: Aug 30, 2013
 *      Author: Nathan Lane
 *       Class: CSIS-2430
 */

#include <stdio.h>

#include "nathansort.h"
#include "printarrays.h"
#include "lists.h"

/**
 * This is a unique sorting algorithm, but I think it is 
 * pretty slow - something like: O((n!)^n).
 */
void nathansort(int * unsortedList, const size_t size)
{
  static int * newList;
  int * copyOfList;
  int * listToWorkOn;
  int listIndex;
  int lowestValue;
  size_t remainingSize = size;

  if (size < 2)
  {
    return;
  }

  copyOfList = makeDeepCopyOfArray(unsortedList, size);
  listToWorkOn = copyOfList;
  
  newList = calloc(size, sizeof(int));
  
  while (remainingSize > 0)
  {
    lowestValue = listToWorkOn[(remainingSize - 1)];

    /* Find lowset value in list first */
    listIndex = 0;

    while (listIndex < remainingSize)
    {
      if (listToWorkOn[listIndex] < lowestValue)
      {
        lowestValue = listToWorkOn[listIndex];
      }

      listIndex++;
    }

    listToWorkOn = copyOfList;

    /* Find the point where the lowest value is */
    listIndex = 0;

    while (listToWorkOn[listIndex] != lowestValue)
    {
      listIndex++;
    }

    /* Shift every value to the left 1 space, removing the "lowest value" */
    while (listIndex < (remainingSize - 1))
    {
      listToWorkOn[listIndex] = listToWorkOn[(listIndex + 1)];

      listIndex++;
    }

    remainingSize--;

    /* Add lowest value to newList */
    newList[(size - remainingSize - 1)] = lowestValue;
  }

  /* Copy newList into unsortedList */
  for (listIndex = 0; listIndex < size; listIndex++)
  {
    unsortedList[listIndex] = newList[listIndex];
  }
}

