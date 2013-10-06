/*
 * caesarCipher.c
 *
 * Testing Fibonacci method - iterative version.
 *
 *  Created on: Oct 2, 2013
 *      Author: Nathan Lane
 *       Class: CSIS-2430
 */

#include "caesarCipher.h"

#include <string.h>
#include <stdio.h>
#include <ctype.h>

char * possibleValues = "abcdefghijklmnopqrstuvwxyz";

int getIndexOfP(char p)
{
  int indexOfP;
  char * cPtr = strchr(possibleValues, p);
  
  if (cPtr == NULL)
  {
    p = tolower(p);
    cPtr = strchr(possibleValues, p);
  }
  
  indexOfP = (int) (cPtr - possibleValues);
  
  return indexOfP;
}

char encrypt(short int k, char p)
{
  int indexOfP = getIndexOfP(p);
  int indexOfEp = ((indexOfP + k) % 26);  
  
  /* Wrap if the index is less than zero. */
  if (indexOfEp < 0)
  {
    indexOfEp = (26 + indexOfEp);
  }
  
  return possibleValues[indexOfEp];
}

char decrypt(short int k, char p)
{
  int indexOfP = getIndexOfP(p);
  int indexOfDp = ((indexOfP - k) % 26);

  /* Wrap if the index is less than zero. */
  if (indexOfDp < 0)
  {
    indexOfDp = (26 + indexOfDp);
  }
  
  return possibleValues[indexOfDp];
}
