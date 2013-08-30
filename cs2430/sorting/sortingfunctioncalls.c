/*
 * sortingfunctioncalls.c
 *
 *  Created on: Aug 30, 2013
 *      Author: Nathan Lane
 *       Class: CSIS-2430
 */
 
#include <time.h>
#include <stdio.h>

#include "sortingfunctioncalls.h"
#include "lists.h"

/**
 * Note: using clock() and CLOCKS_PER_SEC came from:
 *   URL: http://stackoverflow.com/a/5249150
 *   Accessed on: 28 August 2013
 */
double sortUsingArbitrarilySlowSort(int * unsortedList, const size_t size)
{
  int * copyOfList;
  clock_t startOfTask;
  clock_t endOfTask;
  
  copyOfList = makeDeepCopyOfArray(unsortedList, size);
  
  printf("Unsorted list (ArbSlow Sort): ");
  printarray(copyOfList, size);

  startOfTask = clock();
  
  arbslowsort(copyOfList, size);
  
  endOfTask = clock();

  printf("Sorted list (ArbSlow Sort): ");
  printarray(copyOfList, size);
  
  return (double)((endOfTask - startOfTask) / CLOCKS_PER_SEC);
}

/**
 * Note: using clock() and CLOCKS_PER_SEC came from:
 *   URL: http://stackoverflow.com/a/5249150
 *   Accessed on: 28 August 2013
 */
double sortUsingBubbleSort(int * unsortedList, const size_t size)
{
  int * copyOfList;
  clock_t startOfTask;
  clock_t endOfTask;
  
  copyOfList = makeDeepCopyOfArray(unsortedList, size);
  
  printf("Unsorted list (Bubble Sort): ");
  printarray(copyOfList, size);

  startOfTask = clock();
  
  bubblesort(copyOfList, size);
  
  endOfTask = clock();

  printf("Sorted list (Bubble Sort): ");
  printarray(copyOfList, size);
  
  return (double)((endOfTask - startOfTask) / CLOCKS_PER_SEC);
}

/**
 * Note: using clock() and CLOCKS_PER_SEC came from:
 *   URL: http://stackoverflow.com/a/5249150
 *   Accessed on: 28 August 2013
 */

double sortUsingQuicksort(int * unsortedList, const size_t size)
{
  int * copyOfList;
  clock_t startOfTask;
  clock_t endOfTask;
  
  copyOfList = makeDeepCopyOfArray(unsortedList, size);
  
  printf("Unsorted list (Quicksort): ");
  printarray(copyOfList, size);

  startOfTask = clock();
  
  quicksort(copyOfList, size);
  
  endOfTask = clock();

  printf("Sorted list (Quicksort): ");
  printarray(copyOfList, size);
  
  return (double)((endOfTask - startOfTask) / CLOCKS_PER_SEC);
}
