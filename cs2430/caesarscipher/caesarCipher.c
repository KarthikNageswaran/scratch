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

int getIndexOfC(char c)
{
  int indexOfC;
  char * cPtr = strchr(possibleValues, c);
  
  if (cPtr == NULL)
  {
    c = tolower(c);
    cPtr = strchr(possibleValues, c);
  }
  
  indexOfC = (int) (cPtr - possibleValues);
  
  return indexOfC;
}

char encrypt(short int offset, char c)
{
  int indexOfC = getIndexOfC(c);
  int indexOfEc = ((indexOfC + offset) % 26);  
  char encryptedChar = possibleValues[indexOfEc];
  
  return encryptedChar;
}

char decrypt(short int offset, char c)
{
  int indexOfC = getIndexOfC(c);
  int indexOfDc = ((indexOfC - offset) % 26);
  
  if (indexOfDc < 0)
  {
    indexOfDc = (26 + indexOfDc);
  }
  
  char decryptedChar = possibleValues[indexOfDc];
  
  return decryptedChar;
}
