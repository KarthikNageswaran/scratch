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
#include <stdbool.h>
#include <stdio.h>

char * possibleValues = "abcdefghijklmnopqrstuvwxyz";

int getIndexOfP(char p)
{
  int indexOfP;
  char * cPtr = strchr(possibleValues, p);
  
  if (cPtr == NULL)
  {
    c = tolower(p);
    cPtr = strchr(possibleValues, p);
  }
  
  indexOfP = (int) (cPtr - possibleValues);
  
  return indexOfP;
}

char encrypt(short int k, char p)
{
  int indexOfP = getIndexOfP(p);
  int indexOfEc = ((indexOfP + k) % 26);  
  char encryptedChar = possibleValues[indexOfEc];
  
  return encryptedChar;
}

char decrypt(short int k, char p)
{
  int indexOfP = getIndexOfP(p);
  int indexOfDp = ((indexOfP - k) % 26);

  // Not certain why I need this hack.  
  if (indexOfDp < 0)
  {
    indexOfDp = (26 + indexOfDp);
  }
  
  char decryptedChar = possibleValues[indexOfDp];
  
  return decryptedChar;
}
