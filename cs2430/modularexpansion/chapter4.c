/*
 * chapter4.c
 *
 *  Created on: Sep 7, 2013
 *      Author: Nathan Lane
 *       Class: CSIS-2430
 */
 
 #include "algorithmone.h"
 #include "algorithmfive.h"
 
 #include <stdlib.h>
 #include <stdio.h>
 
 int main(int argv, char * argc[])
 {
   char * expandedValue;
   int number;
   int exponent;
   int modulation;
   size_t size = 0;
   
   if (argv != 4)
   {
     printf("usage: %s base-number exponent modulation\n", argc[0]);
	 
	 return 1;
   }
   
   number = atoi(argc[1]);
   exponent = atoi(argc[2]);
   modulation = atoi(argc[3]);
   
   expandedValue = baseexpansion(exponent, 2, &size);
   
   printf("Result of %i^%i mod %i = %i\n", number, exponent, modulation, modexp(number, expandedValue, size, modulation));
   
   return 0;
 }
 