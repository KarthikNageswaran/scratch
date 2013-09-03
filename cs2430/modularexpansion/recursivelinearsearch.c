/*
 * recursivelinearsearch.c
 *
 *  Created on: Sep 3, 2013
 *      Author: Nathan Lane
 *       Class: CSIS-2430
 */

#include "recursivelinearsearch.h"

/**
 * Recursive linear search algorithm.
 *
 * where:
 *  - searchList is a list of integers.
 *  - index is an index in the list of integers.
 *  - size is the size of the list.
 *  - searchTerm is the integer being search for.
 *
 * returns:
 *  -1 if searchTerm is not found.
 *  index of searchTerm if searchTerm is found.
 */
int search(const int * searchList, const int index, const size_t size, const int searchTerm)
{
  if (index >= size)
  {
    return -1;
  }
  else if (searchList[index] == searchTerm)
  {
    return index;
  }

  return search(searchList, index++, size, searchTerm);
}

