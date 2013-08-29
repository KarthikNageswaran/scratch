/*
 * lists.c
 *
 *  Created on: Aug 28, 2013
 *      Author: Nathan Lane
 *       Class: CSIS-2430
 */

#include <stdio.h>

#include "lists.h"
#include "printarrays.h"

/**
 * Creates a deep copy of another array.
 */
int * makeDeepCopyOfArray(const int * original, const size_t size)
{
  int * list;
  int index;

  list = calloc(size, sizeof(int));
  
  for (index = 0; index < size; index++)
  {
    list[index] = original[index];
  }
  
  return list;
}

/**
 * Concatenates two lists and returns the new list.
 */
int * concatenateLists(const int * first, const size_t firstSize, const int * second, const size_t secondSize)
{
  static int * newList;
  int index;
  int newListIndex;
  
  newList = calloc((firstSize + secondSize), sizeof(int));
  
  for (index = 0, newListIndex = 0; index < firstSize; index++, newListIndex++)
  {
    newList[newListIndex] = first[index];
  }
  
  for (index = 0, newListIndex = 0; index < secondSize; index++, newListIndex++)
  {
    newList[newListIndex] = second[index];
  }

  printarray(newList, (firstSize + secondSize));
  
  return newList;
}

/**
 * Creates a list with a single item.
 */
int * list(int singleItem)
{
  static int * newList;
  
  newList = calloc(1, sizeof(int));
  
  newList[0] = singleItem;
  
  return newList;
}

/**
 * Creates a sublist from an existing list.
 */
int * subList(const int * otherList, const size_t otherListSize, int leftIndex, const size_t size)
{
  static int * newList;
  int * copyOfOtherList;
  int otherListIndex;
  int index;
  int valueToBeAdded;

  copyOfOtherList = makeDeepCopyOfArray(otherList, otherListSize);

  newList = calloc(size, sizeof(int));

  for (index = 0, otherListIndex = leftIndex; (index < size && otherListIndex < otherListSize); otherListIndex++, index++)
  {
    valueToBeAdded = copyOfOtherList[otherListIndex];

    newList[index] = valueToBeAdded;
  }

  return newList;
}

int * resize(const int * list, const size_t size)
{
  static int * newList;
  int index;

  newList = calloc(size, sizeof(int));

  for (index = 0; index < size; index++)
  {
    newList[index] = list[index];
  }

  return newList;
}

