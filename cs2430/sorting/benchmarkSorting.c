/*
 * benchmarkSorting.c
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
#include "nathansort.h"
#include "randomgenerator.h"
#include "lists.h"
#include "printarrays.h"

#define NUM_CYCLES 1
#define NUM_ELEMENTS 100000
#define MIN_VAL 1
#define MAX_VAL 100000

double benchmarkSortingAlgorithm(void (* sortingAlgorithm)(int *, const size_t))
{
  double benchmark;
  double total;
  int numCycles;
  clock_t startOfTask;
  clock_t endOfTask;
  int * intList;
  int * copyOfList;

  total = 0.0;
  benchmark = 0.0;
  numCycles = 1;

  printf(".");

  while (numCycles <= NUM_CYCLES)
  {
    intList = generateRandomArray(NUM_ELEMENTS, MIN_VAL, MAX_VAL);
    copyOfList = makeDeepCopyOfArray(intList, NUM_ELEMENTS);

    printf("Generated random list.\n");

    startOfTask = clock();

    (* sortingAlgorithm)(copyOfList, NUM_ELEMENTS);

    endOfTask = clock();

    printf("Sorted list.\n");

    total = (((numCycles - 1) * benchmark) + (double) ((endOfTask - startOfTask) / CLOCKS_PER_SEC));
    benchmark = (total / (double) numCycles);

    numCycles++;
  }
  
  free(copyOfList);
  free(intList);

  return benchmark;
}

int main(int argc, char * argv[])
{
  void (* sortingAlgorithm) (int *, const size_t);
  
  setlocale(LC_NUMERIC, "");

  printf("Clocks per second: %li.\n\n", CLOCKS_PER_SEC);
  printf("Sorting lists of %i shuffled integers...\n", NUM_ELEMENTS);
  
  sortingAlgorithm = bubblesort;  
  printf("Time for bubble sort: %lf sec. (list size: %i, iterations: %i)\n\n", benchmarkSortingAlgorithm(sortingAlgorithm), NUM_ELEMENTS, NUM_CYCLES);
  sortingAlgorithm = quicksort;
  printf("Time for quick sort: %lf sec. (list size: %i, iterations: %i)\n\n", benchmarkSortingAlgorithm(sortingAlgorithm), NUM_ELEMENTS, NUM_CYCLES);
  sortingAlgorithm = nathansort;
  printf("Time for nathan sort: %lf sec. (list size: %i, iterations: %i)\n\n", benchmarkSortingAlgorithm(sortingAlgorithm), NUM_ELEMENTS, NUM_CYCLES);

  return 0;
}
