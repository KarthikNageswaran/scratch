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

int partition(int * subList, int left, int right, int pivotIndex)
{
  int pivotValue;
  int swapValue;
  int storeIndex;
  int index;
  
  pivotValue = subList[pivotIndex];
  swapValue = subList[right];
  
  subList[right] = subList[pivotIndex];
  subList[pivotIndex] = swapValue;
  
  storeIndex = left;
  
  for (index = left; index < right; index++)
  {
    if (subList[index] < pivotValue)
	{
	  swapValue = subList[index];
	  
	  subList[index] = subList[storeIndex];
	  subList[storeIndex] = swapValue;
	  
	  storeIndex++;
	}
  }
  
  swapValue = subList[storeIndex];
  
  subList[storeIndex] = subList[right];
  subList[right] = swapValue;
  
  return storeIndex;
}

/**
 * Quicksort algorithm based on Wikipedia entry on Bubble Sort.
 *   URL: http://en.wikipedia.org/wiki/Quicksort
 *   Accessed on: 28 August 2013
 */
void quicksort(int * unsortedList, const size_t size, const int left, const int right)
{
  int pivotIndex;
  int pivotNewIndex;
  
  if (size > 1 && left < right)
  {
    srand(time(NULL));
    
    pivotIndex = (rand() % (size - 1));
    
	pivotNewIndex = partition(unsortedList, left, right, pivotIndex);
	
    quicksort(unsortedList, size, left, pivotNewIndex - 1);
 
    quicksort(unsortedList, size, pivotNewIndex + 1, right);
  }
}
