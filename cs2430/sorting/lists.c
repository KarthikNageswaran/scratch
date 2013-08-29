/*
 * lists.c
 *
 *  Created on: Aug 28, 2013
 *      Author: Nathan Lane
 *       Class: CSIS-2430
 */

#include "lists.h"

/**
 * Creates a deep copy of another array.
 */
int * makeDeepCopyOfArray(const int * original, const size_t size)
{
  int * list;
  int index;
  
  list = malloc(sizeof(original));
  
  for (index = 0; index < size; index++)
  {
    list[index] = original[index];
  }
  
  return list;
}

/**
 * Concatenates two lists and returns the new list.
 */
int * concatenateLists(int * first, int * second)
{
  static int * newList;
  size_t size;
  int index;
  int newListIndex;
  
  size = ((sizeof(first) + sizeof(second)) / sizeof(int));
  
  newList = calloc(size, sizeof(int));
  
  for (index = 0, newListIndex = 0; index < (sizeof(first) / sizeof(int)); index++, newListIndex++)
  {
    newList[newListIndex] = first[index];
  }
  
  for (index = 0, newListIndex = 0; index < (sizeof(second) / sizeof(int)); index++, newListIndex++)
  {
    newList[newListIndex] = second[index];
  }
  
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
