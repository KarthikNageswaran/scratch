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
    printf("usage: %s <command> <k> <message>\n", argc[0]);
    printf("Caesar Cipher (encrypt: (p+k) mod 26, decrypt: (p-k) mod 26\n");
    printf("  command: must be either encrypt or decrypt\n");
    printf("  k: unsigned (positive) value used to shift alphabet per Caesar Cipher\n");
    printf("  message: message to either encrypt or decrypt. This is p.\n");
    
    return 1;
  }
  
  command = argc[1];
  shiftValue = atoi(argc[2]);
  message = argc[3];
  start = message;
  
  if (strcmp("encrypt", command) == 0)
  {
    printf("Plain text: %s\n", message);
  }
  else if (strcmp("decrypt", command) == 0)
  {
    printf("Cipher text: %s\n", message);
  }

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
        printf("Command %s is unknown.\n", argc[1]);
        
        return 2;
      }
    }
    
    message++;
  }
  
  message = start;
  
  printf("%s\n", message);
  
  return 0;
}
