/*
 * randomgenerator.c
 *
 *  Created on: Aug 28, 2013
 *      Author: Nathan Lane
 *       Class: CSIS-2430
 */

#include <stdlib.h>
#include <time.h>

#include "randomgenerator.h"

#define MAX_POSSIBLE_VALUES 1000

/**
 * Generates a list of 1,000 possible values (1..1000).
 */
int * generateListOfPossibleValues()
{
  static int controlArray[1000];
  int index;

  for (index = 0; index < MAX_POSSIBLE_VALUES; index++)
  {
    controlArray[index] = (index + 1);
  }

  return controlArray;
}

/**
 * Shuffles a list of possible values.
 */
int * shufflePossibleValues(int * possibleValues)
{
  int index;
  int nextRand;
  int swapValue;

  srand(time(NULL));

  for (index = 0; index < MAX_POSSIBLE_VALUES; index++)
  {
    nextRand = rand() % 1000;

    swapValue = possibleValues[index];

    possibleValues[index] = possibleValues[nextRand];
    possibleValues[nextRand] = swapValue;
  }

  return possibleValues;
}

/**
 * Generates a random list of numbers - exposed by randomgenerator.h.
 */ 
int * generateRandomArray(size_t maxArraySize)
{
  static int * array;
  int * shuffledValues = shufflePossibleValues(generateListOfPossibleValues());
  int index;

  array = (int *) calloc(maxArraySize, sizeof(int));

  for (index = 0; index < maxArraySize; index++)
  {
    array[index] = shuffledValues[index];
  }

  return array;
}

