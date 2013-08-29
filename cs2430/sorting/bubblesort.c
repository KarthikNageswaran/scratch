/*
 * bubblesort.c
 *
 *  Created on: Aug 27, 2013
 *      Author: Nathan Lane
 *       Class: CSIS-2430
 */

#include <stdbool.h>

#include "bubblesort.h"

/**
 * Bubble Sort algorithm based on Wikipedia entry on Bubble Sort.
 *   URL: http://en.wikipedia.org/wiki/Bubble_sort
 *   Accessed on: 27 August 2013
 */
void bubblesort(int * unsortedList, const size_t numberOfElements)
{
  bool itemsWereSwapped;
  int index;
  int swapValue;

  if (numberOfElements < 2)
  {
    return;
  }

  do
  {
    itemsWereSwapped = false;

    for (index = 0; index < (numberOfElements - 1); index++)
    {
      if (unsortedList[index] > unsortedList[(index + 1)])
      {
        swapValue = unsortedList[index];

        unsortedList[index] = unsortedList[(index + 1)];
        unsortedList[(index + 1)] = swapValue;

        itemsWereSwapped = true;
      }
    }
  }
  while (itemsWereSwapped);
}
