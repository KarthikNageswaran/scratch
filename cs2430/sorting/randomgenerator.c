/*
 * randomgenerator.c
 *
 *  Created on: Aug 28, 2013
 *      Author: Nathan Lane
 *       Class: CSIS-2430
 */

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "randomgenerator.h"

/**
 * Generates a list of maxValue possible values (minValue..maxValue).
 */
int * generateListOfPossibleValues(const unsigned int minValue, const unsigned int maxValue)
{
  static int * controlArray;
  int index;
  
  controlArray = calloc((maxValue - minValue), sizeof(int));

  for (index = minValue; index <= maxValue; index++)
  {
    controlArray[index] = (index + 1);
  }

  return controlArray;
}

/**
 * Shuffles a list of possible values.
 */
int * shufflePossibleValues(int * possibleValues, const size_t numValues)
{
  int index;
  int nextRand;
  int swapValue;

  srand(time(NULL));

  for (index = 0; index < numValues; index++)
  {
    nextRand = rand() % numValues;

    swapValue = possibleValues[index];

    possibleValues[index] = possibleValues[nextRand];
    possibleValues[nextRand] = swapValue;
  }

  return possibleValues;
}

/**
 * Generates a random list of numbers - exposed by randomgenerator.h.
 */ 
int * generateRandomArray(const size_t arraySize, const unsigned int minValue, const unsigned int maxValue)
{
  static int * array;
  int * shuffledValues = shufflePossibleValues(generateListOfPossibleValues(minValue, maxValue), arraySize);
  int index;

  array = calloc(arraySize, sizeof(int));

  for (index = 0; index < arraySize; index++)
  {
    array[index] = shuffledValues[index];
  }

  return array;
}
