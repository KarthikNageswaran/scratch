#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>

uint_fast64_t recursive_fib(uint_fast64_t n)
{
  if (n == 0)
  {
    return 0;
  }
  else if (n == 1)
  {
    return 1;
  }

  return recursive_fib(n - 1) + recursive_fib(n - 2);
}

int main(int argv, char * argc[])
{
  time_t start;
  time_t stop;
  clock_t ticks;
  uint_fast64_t index;
  char * end;
  
  index = strtoull(argc[1], &end, 10);
  
  time(&start);
  
  printf("%" PRIu64 "\n", recursive_fib(index));
  
  ticks = clock();
  
  time(&stop);
  
  printf("Execution time: %0.0f seconds.\n", (double)ticks / CLOCKS_PER_SEC);
  
  return 0;
}
