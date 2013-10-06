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
#include <stdbool.h>
#include <ctype.h>

void printUsage(char * programName)
{
  printf("usage: %s <command> <k> <message>\n", programName);
  printf("Caesar Cipher (encrypt: (p+k) mod 26, decrypt: (p-k) mod 26)\n");
  printf("  command: must be either encrypt or decrypt\n");
  printf("  k: unsigned (positive) value used to shift alphabet per Caesar Cipher\n");
  printf("  message: message to either encrypt or decrypt. This is p.\n");
}

bool kIsNumeric(char * k)
{
  while (*k != '\0')
  {
    if (!isdigit(*k))
    {
      return false;
    }
    
    k++;
  }
  
  return true;
}

void performCommand(char * command, char * message, short int k)
{
  char * possibleValues = "abcdefghijklmnopqrstuvwxyz";
  char * start;
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
    if (strchr(possibleValues, *message) != NULL || strchr(possibleValues, tolower(*message)) != NULL)
    {
      if (strcmp("encrypt", command) == 0)
      {
        *message = encrypt(k, *message);
      }
      else if (strcmp("decrypt", command) == 0)
      {
        *message = decrypt(k, *message);
      }
      else {
        printf("Command %s is unknown.\n", command);
        
        exit(2);
      }
    }
    
    message++;
  }
  
  message = start;
}
 
int main(int argv, char * argc[])
{
  char * command;
  char * message;
  short int k;
  
  if (argv != 4)
  {
    printUsage(argc[0]);
    
    return 1;
  }
  else if (!kIsNumeric(argc[2]))
  {
    printf("k must be numeric.\n");
    
    return 2;
  }
  
  command = argc[1];
  k = atoi(argc[2]);
  message = argc[3];

  performCommand(command, message, k);  
  
  printf("%s\n", message);
  
  return 0;
}
