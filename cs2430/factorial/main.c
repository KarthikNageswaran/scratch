#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mathfunctions.h"

#define BUFFERSIZE 30

int main()
{
  long nValue;
  long factorialResult;
  char userInput[BUFFERSIZE];
  char * end;

  while (1 == 1)
  {
    printf("Please type an integer number to be operated on by the factorial function (q to quit): ");
    
    fgets(userInput, BUFFERSIZE, stdin);

    userInput[strlen(userInput) - 1] = '\0';

    if (strcmp(userInput, "q") == 0)
    {
      printf("quitting...\n");

      return 0;
    }

    nValue = strtol(userInput, &end, 10);

    if (!*end)
    {
      if (nValue >= 0)
      {
        factorialResult = factorial(nValue);

        if (factorialResult < 0)
        {
          printf("%li overflowed signed long, resulting in an invalid value: %li.\n\n", nValue, factorialResult);
        }
        else
        {
          printf("%li! (factorial) = %li.\n\n", nValue, factorialResult);
        }
      }
      else
      {
        printf("Input must be greater than, or equal to zero, but you entered %li.\n\n", nValue);
      }
    }
    else
    {
      printf("Could not convert \"%s\" to signed long.\n\n", userInput);
    }
  }

  return 0;
}

