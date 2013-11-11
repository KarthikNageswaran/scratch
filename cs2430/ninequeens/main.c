/*
 * main.c
 *
 *  Created on: Nov 10, 2013
 *      Author: Nathan Lane
 *       Class: CSIS-2430
 *
 *  Eight Queens
 *
 */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

bool queensAttackEachOther(int q1Index, int q1VIndex, int q2Index, int q2VIndex)
{
  bool attacking = false;
  
  if (q1Index == q2Index || q1VIndex == q2VIndex)
  {
    attacking = true;
  }
  else if (abs(q1VIndex - q2VIndex) / (abs(q1Index - q2Index)) == 1)
  {
    attacking = true;
  }
  
  return attacking;
}

void printArray(int * queensVerticalPositions, int length)
{
  int queenIndex;
  
  for (queenIndex = 0; queenIndex < length; queenIndex++)
  {
    if (queenIndex > 0)
    {
      printf(",");
    }
    
    printf("%d", queensVerticalPositions[queenIndex]);
  }
  
  printf("\n");
}

int main(int argv, char * argc[])
{
  int queensVerticalPositions[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
  int horizontalIndex;
  int verticalIndex;
  int q1Index;
  int q2Index;
  int queenIndex;
  bool noQueensAreAdjacent;

  while (horizontalIndex < 8)
  {
    
  }
  
  return 0;
}
