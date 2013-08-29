/*
 * quicksort.c
 *
 *  Created on: Aug 28, 2013
 *      Author: Nathan Lane
 *       Class: CSIS-2430
 */

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "quicksort.h"
#include "lists.h"
#include "printarrays.h"

/**
 * This algorithm was adapted from rosettacode.com
 *   URL: http://rosettacode.org/wiki/Sorting_algorithms/Quicksort#C
 *   Accessed on: 29 August 2013
 */
void quicksort(int * unsortedList, size_t size)
{
  int * less;
  int * greater;
  int * equal;
  int * newList;
  int lessIndex = 0;
  int greaterIndex = 0;
  int equalIndex = 0;
  int pivotValue;
  int unsortedListIndex;

  printf("\nstarted quicksort: ");
  printarray(unsortedList, size);

  if (size < 2)
  {
    return;
  }

  less = calloc(size, sizeof(int));
  greater = calloc(size, sizeof(int));
  equal = calloc(size, sizeof(int));
  newList = calloc(size, sizeof(int));

  srand(time(NULL));

  pivotValue = unsortedList[(rand() % (size - 1))];

  printf("pivotValue=%i\n", pivotValue);

  for (unsortedListIndex = 0; unsortedListIndex < size; unsortedListIndex++)
  {
    if (unsortedList[unsortedListIndex] < pivotValue)
    {
      less[lessIndex] = unsortedList[unsortedListIndex];

      lessIndex++;
    }
    else if (unsortedList[unsortedListIndex] == pivotValue)
    {
      equal[equalIndex] = unsortedList[unsortedListIndex];

      equalIndex++;
    }
    else if (unsortedList[unsortedListIndex] > pivotValue)
    {
      greater[greaterIndex] = unsortedList[unsortedListIndex];

      greaterIndex++;
    }
  }

  less = resize(less, lessIndex);
  greater = resize(greater, greaterIndex);
  equal = resize(equal, equalIndex);

  printf("less: ");
  printarray(less, lessIndex);
  printf("equal: ");
  printarray(equal, equalIndex);
  printf("greater: ");
  printarray(greater, greaterIndex);

  quicksort(less, lessIndex);
  quicksort(greater, greaterIndex);

  newList = concatenateLists(less, lessIndex, concatenateLists(equal, equalIndex, greater, greaterIndex), (equalIndex + greaterIndex));

  printf("New list: ");
  printarray(newList, size);

  unsortedList = makeDeepCopyOfArray(newList, size);
}

