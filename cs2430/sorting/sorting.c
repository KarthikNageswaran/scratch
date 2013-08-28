/*
 * sorting.c
 *
 *  Created on: Aug 27, 2013
 *      Author: Nathan Lane
 *       Class: CSIS-2430
 */

#include "bubblesort.h"
#include "randomgenerator.h"
#include "printarrays.h"

#define MAX_NUM_ELEMENTS 10

int main()
{
	int * intList = generateRandomArray(MAX_NUM_ELEMENTS);

  printarray(intList, MAX_NUM_ELEMENTS);

	bubblesort(intList, MAX_NUM_ELEMENTS);

  printarray(intList, MAX_NUM_ELEMENTS);

	return 0;
}
