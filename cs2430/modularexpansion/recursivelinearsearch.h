/*
 * recursivelinearsearch.h
 *
 *  Created on: Sep 3, 2013
 *      Author: Nathan Lane
 *       Class: CSIS-2430
 */

#ifndef RECURSIVELINEARSEARCH_H_
#define RECURSIVELINEARSEARCH_H_

#include <stdlib.h>

/**
 * Recursive linear search algorithm.
 *
 * where:
 *  - const int * is a list of integers.
 *  - const int is an index in the list of integers.
 *  - const size_t is the size of the list.
 *  - const int is the integer being search for.
 */
int search(const int *, const int, const size_t, const int);

#endif /* RECURSIVELINEARSEARCH_H_ */
