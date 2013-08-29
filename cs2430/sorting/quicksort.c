/*
 * quicksort.c
 *
 *  Created on: Aug 28, 2013
 *      Author: Nathan Lane
 *       Class: CSIS-2430
 */

#include <stdlib.h>
#include <time.h>

#include "quicksort.h"
#include "lists.h"

void quicksort(int * unsortedList, size_t size)
{
  int pivotValue;
  int swapValue;
  int leftIndex;
  int righIndext;

  leftIndex = 0;
  rightIndex = (size - 1);

  srand(time(NULL));

  pivotValue = unsortedList[(rand() % (size - 1))];

  if (size <= 1)
  {
    return;
  }

  while (leftIndex <= rightIndex)
  {
    while (unsortedList[leftIndex] < pivotValue)
    {
      leftIndex++;
    }

    while (unsortedList[rightIndex] > pivotValue)
    {
      rightIndex--;
    }

    if (leftIndex <= rightIndex)
    {
      swapValue = unsortedList[leftIndex];
      unsortedList[leftIndex] = unsortedList[rightIndex];
      unsortedList[rightIndex] = swapValue;

      leftIndex++;
      rightIndex--;
    }
  }

  quicksort(subList(unsortedList, 0, rightIndex), (rightIndex));
  quicksort(subList(unsortedList, leftIndex, (size - 1)), (size - leftIndex));
}

