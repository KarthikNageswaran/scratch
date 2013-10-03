/*
 * testCaesarCipher.c
 *
 * Testing Fibonacci method - iterative version.
 *
 *  Created on: Oct 2, 2013
 *      Author: Nathan Lane
 *       Class: CSIS-2430
 */

#include "caesarCipher.h"
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(int argv, char * argc[])
{
  char * possibleValues = "abcdefghijklmnopqrstuvwxyz";
  char * command;
  char * message;
  char * start;
  short int shiftValue;
  
  if (argv != 4)
  {
    printf("usage: %s (encrypt|decrypt) <shift-value> <message>\n", argc[0]);
    
    return 1;
  }
  
  command = argc[1];
  shiftValue = atoi(argc[2]);
  message = argc[3];
  start = message;
  
  if (shiftValue < 0)
  {
    printf("Only positive values are allowed for shif-value.\n");
    
    return 3;
  }
  
  if (strcmp("encrypt", command) == 0)
  {
    printf("Plain text: ");
  }
  else if (strcmp("decrypt", command) == 0)
  {
    printf("Cipher text: ");
  }
  
  printf("%s\n", message);

  while (*message != '\0')
  {
    if (strchr(possibleValues, *message) != NULL)
    {
      if (strcmp("encrypt", command) == 0)
      {
        *message = encrypt(shiftValue, *message);
      }
      else if (strcmp("decrypt", command) == 0)
      {
        *message = decrypt(shiftValue, *message);
      }
      else {
        printf("Command %s is unknown.\n", argc[0]);
        
        return 2;
      }
    }
    
    message++;
  }
  
  message = start;
  
  printf("%s\n", message);
  
  return 0;
}
