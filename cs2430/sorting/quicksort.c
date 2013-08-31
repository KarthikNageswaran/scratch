/*
 * quicksort.c
 *
 *  Created on: Aug 28, 2013
 *      Author: Nathan Lane
 *       Class: CSIS-2430
 */

#include "quicksort.h"

/**
 * This algorithm was literally ripped from rosettacode.com. I could not get any of my adaptations to work.
 *   URL: http://rosettacode.org/wiki/Sorting_algorithms/Quicksort#C
 *   Accessed on: 29 August 2013
 */
void quicksort(int * unsortedList, const size_t size)
{
  int pivotValue = unsortedList[size / 2];
  int * left = unsortedList;
  int * right = (unsortedList + size - 1);
  int tempValue;

  if (size < 2)
  {
    return;
  }

  while (left <= right) {
    if ((* left) < pivotValue ) {
      left++;

      continue;
    }

    if ((* right) > pivotValue)  {
      right--;
      continue; // we need to check the condition (l <= r) every time we change the value of l or r
    }

    tempValue = (* left);
    (* left++) = (* right);
    (* right--) = tempValue;
  }
  
  quicksort(unsortedList, (right - unsortedList + 1));
  quicksort(left, (unsortedList + size - left));
}

