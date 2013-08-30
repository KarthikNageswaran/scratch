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
#include <locale.h>

#include "bubblesort.h"
#include "randomgenerator.h"
#include "lists.h"

#define NUM_CYCLES 100
#define NUM_ELEMENTS 10000

double benchmarkBubbleSort()
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
    intList = generateRandomArray(NUM_ELEMENTS, 1, 100000);
    copyOfList = makeDeepCopyOfArray(intList, NUM_ELEMENTS);

    printf(".");

    startOfTask = clock();

    bubblesort(copyOfList, NUM_ELEMENTS);

    endOfTask = clock();

    printf(".");

    total = (((numCycles - 1) * benchmark) + (double) ((endOfTask - startOfTask) / CLOCKS_PER_SEC));
    benchmark = (total / (double) numCycles);

    printf("cycle: %i, total: %f, benchmark: %f\n", numCycles, total, benchmark);

    numCycles++;
  }

  return benchmark;
}

int main(int argc, char * argv[])
{
  double overallClocksPerSecond;
  
  setlocale(LC_NUMERIC, "");

  /* Using ' to format numbers with commas between every third and fourth digit.
   *    URL: http://stackoverflow.com/questions/11694901/how-can-i-format-currency-with-commas-in-c
   *    Accessed on 29 August 2013 */
  printf("Clocks per second: %'li.\n\n", CLOCKS_PER_SEC);
  printf("Time for bubble sort: %'.4lf sec\n\n", benchmarkBubbleSort());

  return 0;
}
