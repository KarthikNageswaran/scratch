/*
 * lists.h
 *
 *  Created on: Aug 28, 2013
 *      Author: Nathan Lane
 *       Class: CSIS-2430
 */

#ifndef LISTS_H_
#define LISTS_H_

#include <stdlib.h>

int * makeDeepCopyOfArray(const int *, const size_t);

int * concatenateLists(int *, int *);

int * list(int);

int * subList(const int *, int, int);

#endif /* LISTS_H_ */
