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
 *  - uint64_t base of an exponent
 *  - uint64_t exponent
 *  - uint64_t number to modulate against
 */
uint64_t recmodexp(uint64_t, uint64_t, uint64_t);
 
#endif /* RECMODEXP_H_ */
