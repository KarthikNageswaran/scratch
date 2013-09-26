/*
 * recmodexp.h
 *
 * Recursive modular exponentiation.
 *
 *  Created on: Sep 23, 2013
 *      Author: Nathan Lane
 *       Class: CSIS-2430
 */
 
#ifndef RECMODEXP_H_
#define RECMODEXP_H_

#include <stdint.h>
 
/**
 * Modular exponentiation algorithm.
 * 
 * where:
 *  - int base of an exponent
 *  - int exponent
 *  - int number to modulate against
 */
int recmodexp(int, int, int);
 
#endif /* RECMODEXP_H_ */
