/*
 * testBayesGenTheorem.c
 *
 *  Created on: Oct 13, 2013
 *      Author: Nathan Lane
 *       Class: CSIS-2430
 */

#include <stdio.h>
#include <stdlib.h>

#include "bayesGeneralTheorem.h"

int main(int argc, char * argv[])
{
  double baseCase;
  double probabilityOfEGivenF;
  double probabilityOfNotEGivenNotF;
  
  if (argc != 4)
  {
    printf("usage: %s <num-cases-E-given-population> <prob-E-given-F> <prob-notE-given-notF>\n", argv[0]);
    
    return 1;
  }
  
  baseCase = atof(argv[1]);
  probabilityOfEGivenF = atof(argv[2]);
  probabilityOfNotEGivenNotF = atof(argv[3]);
  
  printf("Calculating p(F|E)...\nBase case: %f\np(E|F): %f\np(!E|!F): %f\n", baseCase, probabilityOfEGivenF, probabilityOfNotEGivenNotF);
  printf("p(E|F): %d\n\n", calculatePOfFGivenE(baseCase, probabilityOfEGivenF, probabilityOfNotEGivenNotF));
  
  return 0;
}
