/*
 * bubblesort.c
 *
 *  Created on: Aug 27, 2013
 *      Author: Nathan Lane
 *       Class: CSIS-2430
 */

#include <stdbool.h>

#include "bubblesort.h"

void bubblesort(int unsortedList[], int numberOfElements)
{
  bool itemsWereSwapped;
  int index;
  int swapValue;

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
