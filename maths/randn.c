#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argv, char ** argc)
{
  unsigned int totalNumbers;
  unsigned int randomValue;
  unsigned long counter;
  unsigned long modulus;
  char * end;
  time_t now;
  struct tm * tm;

  if (argv < 2)
  {
    printf("usage: a.out modulus num-numbers");

    return 1;
  }
  
  now = time(0);

  if ((tm = localtime(&now)) == NULL)
  {
    printf("WARN: Cannot extract time stuff. Defaulting to modulus value.");
    
    modulus = strtol(argc[1], &end, 10);
  }
  else
  {
    if (tm->tm_sec > 0)
    {
      modulus = tm->tm_sec;
    }
  }

  totalNumbers = atoi(argc[2]);

  if (totalNumbers > 0)
  {
    srand(time(NULL));

    for (counter = 0; counter < totalNumbers; counter++)
    {
      randomValue = rand() % modulus;

      printf("%d\n", randomValue);
    }
  }

  return 0;
}
