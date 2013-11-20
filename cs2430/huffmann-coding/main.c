/*
 * main.c
 *
 *  Created on: Nov 10, 2013
 *      Author: Nathan Lane
 *       Class: CSIS-2430
 *
 * Huffman Coding.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

const char * validValues = "abcdefghijklmnopqrstuvwxyz";

struct tree_node
{
  char symbol;
  struct tree_node * left_node;
  struct tree_node * right_node;
};

struct tree_node * generate_huffman_code(double symbolHeuristics[],  struct tree_node * root)
{
  
  
  return NULL;
}

int main()
{
  FILE * loremIpsumFile;
  int symbolCounts[26] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
  double symbolHeuristics[26] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
  int c;
  int indexOfC;
  char * val;
  int i;
  int sum;
  double total;
  struct tree_node root;
  
  loremIpsumFile = fopen("loremipsum-4000.txt", "r");
  
  if (loremIpsumFile == NULL) {
    printf("Could not open file loremipsum-4000.txt for reading.\n");
    
    return 1;
  }
  
  i = 0;
  
  do
  {
    c = fgetc(loremIpsumFile);
    val = strchr(validValues, (char) c);
    indexOfC = (int) (val - validValues);
    
    symbolCounts[indexOfC] = symbolCounts[indexOfC] + 1;
    
    i++;
  }
  while (i < 4000);
  
  fclose(loremIpsumFile);
  
  printf("Lorem Ipsum File Heuristics:\n\n");
  
  sum = 0;
  
  for (i = 0; i < 26; i++)
  {
    if (i > 0)
    {
      printf(", ");
    }
    
    printf("%c=%d", validValues[i], symbolCounts[i]);
    
    sum += symbolCounts[i];
  }
  
  total = 0.0;
  
  printf("\n\nSum: %i\n\n", sum);
  
  for (i = 0; i < 26; i++)
  {
    if (i > 0)
    {
      printf(", ");
    }
    
    symbolHeuristics[i] = (((double) symbolCounts[i] / (double) sum) * 100.0);
    
    printf("%c: %.2f", validValues[i], symbolHeuristics[i]);
    
    total += symbolHeuristics[i];
  }
  
  printf("\n\nTotal: %f\n\n", total);
  
  if (floor(total) == 100.0)
  {
    generate_huffman_code(symbolHeuristics, &root);
  }
  else
  {
    printf("Malfunction occurred - total was not 100%\n");
    
    return 2;
  }
  
  return 0;
}
