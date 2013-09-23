/**
 * Main test of baseexpansion.
 */

#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
 
#include "baseexpansion.h"

int main(int argv, char * argc [])
{
  int largestVal = atoi(argc[1]);
  int base = atoi(argc[2]);
  char * boolVal;
  size_t size;
  
  boolVal = baseexpansion(largestVal, base, &size);
   
  printf("Result of %i expanded to base %i is %s.\n", largestVal, base, boolVal);
  
  return 0;
}
