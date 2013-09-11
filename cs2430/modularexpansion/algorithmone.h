/*
 * algorithmone.h
 *
 *  This is the base expansion algorithm with a few adjustments 
 *  from the book.
 *
 *  Created on: Sep 7, 2013
 *      Author: Nathan Lane
 *       Class: CSIS-2430
 */

#ifndef ALGORITHMONE_H_
#define ALGORITHMONE_H_

#include <stdlib.h>

/**
 * Base expansion algorithm - assumes you want to convert from int.
 * 
 * where:
 *  - int original integer
 *  - int base to expand to
 *  - size_t pointer to size of result
 */
char * baseexpansion(int, int, size_t *);

#endif /* ALGORITHMONE_H_ */
