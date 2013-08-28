/*
 * bubblesort.c
 *
 *  Created on: Aug 27, 2013
 *      Author: Nathan Lane
 *       Class: CSIS-2430
 */

#include <stdbool.h>

#include "bubblesort.h"

void bubblesort(int unsortedList[], int numberOfElements)
{
	bool listIsSorted = false;
	int index = 0;
	int checkIndex = 0;
	int swapValue = 0;

	while (true) {
		if (index > (numberOfElements - 2))
		{
			index = 0;
		}

		if (unsortedList[index] > unsortedList[(index + 1)])
		{
			swapValue = unsortedList[index];

			unsortedList[index] = unsortedList[(index + 1)];
			unsortedList[(index + 1)] = swapValue;
		}

		index++;

		if (index == (numberOfElements - 1))
		{
			listIsSorted = true;

			for (checkIndex = 0; checkIndex < (numberOfElements - 1); checkIndex++)
			{
				if (unsortedList[checkIndex] > unsortedList[(checkIndex + 1)])
				{
					listIsSorted = false;

					break;
				}
			}
		}

		if (listIsSorted)
		{
			break;
		}
	}
}
