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
#include "arbslowsort.h"
#include "randomgenerator.h"
#include "sortingfunctioncalls.h"

#define MAX_NUM_ELEMENTS 100

int main(int argc, char * * argv)
{
  int * intList = generateRandomArray(MAX_NUM_ELEMENTS, 1, 1000);

  setlocale(LC_NUMERIC, "");

  /* Using ' to format numbers with commas between every third and fourth digit.
   * URL: http://stackoverflow.com/questions/11694901/how-can-i-format-currency-with-commas-in-c; Accessed on 29 August
   * 2013 */
  printf("Clocks per second: %'li.\n\n", CLOCKS_PER_SEC);
  printf("Time for bubble sort: %'.4lf sec\n\n", sortUsingBubbleSort(intList, MAX_NUM_ELEMENTS));
  printf("Time for quicksort: %'.4lf sec\n\n", sortUsingQuicksort(intList, MAX_NUM_ELEMENTS));
  printf("Time for arbslowsort: %'.4lf sec\n\n", sortUsingArbitrarilySlowSort(intList, MAX_NUM_ELEMENTS));

  return 0;
}
