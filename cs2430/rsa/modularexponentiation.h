/*
 * modularexponentiation.h
 *
 *  This is the modular exponentiation algorithm with a few adjustments 
 *  from the book.
 *
 *  Created on: Sep 21, 2013
 *      Author: Nathan Lane
 *       Class: CSIS-2430
 */

#ifndef ALGORITHMFIVE_H_
#define ALGORITHMFIVE_H_

#include <stdlib.h>

/**
 * Modular exponentiation algorithm.
 * 
 * where:
 *  - int base of an exponent
 *  - char * exponent in binary expansion form
 *  - size_t size of exponent
 *  - int number to modulate against
 */
int modexp(int, char *, size_t, int);

#endif /* ALGORITHMFIVE_H_ */
