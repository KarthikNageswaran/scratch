/*
 * sorting.c
 *
 *  Created on: Aug 27, 2013
 *      Author: Nathan Lane
 *       Class: CSIS-2430
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#include "bubblesort.h"
#include "quicksort.h"
#include "randomgenerator.h"
#include "printarrays.h"
#include "lists.h"

#define MAX_NUM_ELEMENTS 100

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
  
  printf("Unsorted list: ");
  printarray(copyOfList, size);

  startOfTask = clock();
  
  quicksort(copyOfList, size);
  
  endOfTask = clock();

  printf("Sorted list: ");
  printarray(copyOfList, size);
  
  return (double)((endOfTask - startOfTask) / CLOCKS_PER_SEC);
}

int main()
{
  int * intList = generateRandomArray(MAX_NUM_ELEMENTS, 1, 1000);

  setlocale(LC_NUMERIC, "");

  printf("Clocks per second: %'li.\n\n", CLOCKS_PER_SEC);
  printf("Time for bubble sort: %'.4lf sec\n\n", sortUsingBubbleSort(intList, MAX_NUM_ELEMENTS));
  printf("Time for quicksort: %'.4lf sec\n\n", sortUsingQuicksort(intList, MAX_NUM_ELEMENTS));

  return 0;
}
