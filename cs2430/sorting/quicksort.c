/*
 * quicksort.c
 *
 *  Created on: Aug 28, 2013
 *      Author: Nathan Lane
 *       Class: CSIS-2430
 */

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "quicksort.h"
#include "lists.h"
#include "printarrays.h"

/**
 * This algorithm was literally ripped from rosettacode.com. I could not get any of my adaptations to work.
 *   URL: http://rosettacode.org/wiki/Sorting_algorithms/Quicksort#C
 *   Accessed on: 29 August 2013
 */
void quicksort(int * a, size_t n)
{
  int p = a[n / 2];
  int *l = a;
  int *r = a + n - 1;
  int t;

  if (n < 2)
    return;
  while (l <= r) {
    if (*l < p) {
      l++;
      continue;
    }
    if (*r > p) {
      r--;
      continue; // we need to check the condition (l <= r) every time we change the value of l or r
    }
    t = *l;
    *l++ = *r;
    *r-- = t;
  }
  quicksort(a, r - a + 1);
  quicksort(l, a + n - l);
}

