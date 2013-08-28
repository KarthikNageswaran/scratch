/*
 * sorting.c
 *
 *  Created on: Aug 27, 2013
 *      Author: Nathan Lane
 *       Class: CSIS-2430
 */

#include "bubblesort.h"

#define MAX_NUM_ELEMENTS 10

int main()
{
	int intList[MAX_NUM_ELEMENTS] = { 2, 5, 1, 3, 7, 9, 4, 8, 6, 10 };

	bubblesort(intList, MAX_NUM_ELEMENTS);

	return 0;
}
