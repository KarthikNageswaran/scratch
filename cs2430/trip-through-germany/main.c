/*
 * main.c
 *
 *  Created on: Nov 10, 2013
 *      Author: Nathan Lane
 *       Class: CSIS-2430
 *
 * Trip Through Germany.
 */

#include "sqlite3.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int retval;
  sqlite3_stmt * stmt;
  sqlite3 * handle;
  char * val;
  int col;
  int cols;
  
  retval = sqlite3_open("tripthroughgermany", &handle);
  
  if (retval)
  {
    printf("Database connection failed to tripthroughgermany.\n");
    
    return 1;
  }
  
  printf("Connected successfully.\n");
  
  retval = sqlite3_prepare_v2(handle, "select a.location_name from, b.location_name to, kilometers, cost from distance, location a, location b where a.location_id = from_location_id and b.location_id = to_location_id", -1, &stmt, 0);
  
  if (retval)
  {
    printf("Could not query database.\n");
    
    return 2;
  }
  
  cols = sqlite3_column_count(stmt);
  
  while(1)
  {
    retval = sqlite3_step(stmt);

    if(retval == SQLITE_ROW)
    {
      for(col = 0; col < cols; col++)
      {
        val = (char *) sqlite3_column_text(stmt, col);
        
        printf("%s = %s\t", sqlite3_column_name(stmt, col), val);
      }
      
      printf("\n");
    }
    else if(retval == SQLITE_DONE)
    {
      printf("All rows fetched\n");
      
      break;
    }
    else
    {
      printf("Some error encountered\n");
      
      return 3;
    }
  }
  
  return 0;
}
