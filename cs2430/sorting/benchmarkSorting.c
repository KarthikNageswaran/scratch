/*
 *  * sorting.c
 *   *
 *    *  Created on: Aug 27, 2013
 *     *      Author: Nathan Lane
 *      *       Class: CSIS-2430
 *       */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "bubblesort.h"
#include "quicksort.h"
#include "nathansort.h"
#include "randomgenerator.h"
#include "lists.h"
#include "printarrays.h"

#define ARB_INT_MIN 1
#define ARB_INT_MAX 1000000000

double benchmarkSortingAlgorithm(
  void (* sortingAlgorithm)(int *, const size_t), 
  const unsigned int numIterations, 
  const size_t numElements, 
  const unsigned int minValue, 
  const unsigned int maxValue
)
{
  double benchmark;
  double total;
  int iteration;
  clock_t startOfTask;
  clock_t endOfTask;
  int * intList;
  int * copyOfList;

  total = 0.0;
  benchmark = 0.0;
  iteration = 1;

  printf(".");

  while (iteration <= numIterations)
  {
    intList = generateRandomArray(numElements, minValue, maxValue);
    copyOfList = makeDeepCopyOfArray(intList, numElements);

    printf("Generated random list.\n");

    startOfTask = clock();

    (* sortingAlgorithm)(copyOfList, numElements);

    endOfTask = clock();

    printf("Sorted list.\n");

    total = (((iteration - 1) * benchmark) + (double) ((endOfTask - startOfTask) / CLOCKS_PER_SEC));
    benchmark = (total / (double) iteration);

    iteration++;
  }
  
  free(intList);
  free(copyOfList);

  return benchmark;
}

void printUsage(char * programName)
{
  printf("usage: %s <num-iterations> <num-elements> <min-value> <max-value>\n", programName);
  printf("  - num-iterations: number of times to test each algorithm.\n");
  printf("  - num-elements: number of elements to size each unsorted array to.\n");
  printf("  - min-value: minimum value to place in unsorted array.\n");
  printf("  - max-value: maximum value to place in unsorted array.\n");
  printf("  Note that the difference between the max-value and min-value must\n");
  printf("  be greater than, or equal to num-elements.\n");
  printf("\n No value may be less than %i or greater than %i.\n\n", ARB_INT_MIN, ARB_INT_MAX);
}

int main(int argc, char * argv[])
{
  void (* sortingAlgorithm) (int *, const size_t);
  double overallClocksPerSecond;
  unsigned int numIterations;
  unsigned int numElements;
  unsigned int minValue;
  unsigned int maxValue;
  
  if (argc < 5)
  {
    printUsage(argv[0]);
	
	return 1;
  }
  else
  {
    numIterations = atoi(argv[1]);
	numElements = atoi(argv[2]);
	minValue = atoi(argv[3]);
	maxValue = atoi(argv[4]);
	
	if (minValue < ARB_INT_MIN || maxValue > ARB_INT_MAX)
	{
	  printf("Min value or max value was out of range:\n");
	  printf("  - min value may be no less than: %i.\n", ARB_INT_MIN);
	  printf("  - max value may be no more than: %i.\n", ARB_INT_MAX);
	  
	  return 2;
	}
  }
  
  printf("Clocks per second: %li.\n\n", CLOCKS_PER_SEC);
  printf("Sorting lists of %li shuffled integers...\n", numElements);
  printf("Specs: iterations=%i, number of elements=%i, minimum value=%i, maximum value=%i.\n", numIterations, numElements, minValue, maxValue);
  
  sortingAlgorithm = bubblesort;  
  printf("Time for bubble sort: %lf sec. (list size: %li, iterations: %i)\n\n", benchmarkSortingAlgorithm(sortingAlgorithm, numIterations, numElements, minValue, maxValue), numElements, numIterations);
  sortingAlgorithm = quicksort;
  printf("Time for quick sort: %lf sec. (list size: %li, iterations: %i)\n\n", benchmarkSortingAlgorithm(sortingAlgorithm, numIterations, numElements, minValue, maxValue), numElements, numIterations);
  sortingAlgorithm = nathansort;
  printf("Time for nathan sort: %lf sec. (list size: %li, iterations: %i)\n\n", benchmarkSortingAlgorithm(sortingAlgorithm, numIterations, numElements, minValue, maxValue), numElements, numIterations);

  return 0;
}
