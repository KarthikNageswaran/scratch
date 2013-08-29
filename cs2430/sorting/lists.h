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

int * concatenateLists(const int *, const size_t, const int *, const size_t);

int * list(int);

int * subList(const int *, const size_t, int, const size_t);

int * resize(const int *, const size_t);

#endif /* LISTS_H_ */
