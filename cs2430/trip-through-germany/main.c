/*
 * main.c
 *
 *  Created on: Nov 10, 2013
 *      Author: Nathan Lane
 *       Class: CSIS-2430
 *
 * Trip Through Germany.
 */

#include <mysql.h>
#include <stdio.h>

int main()
{
  MYSQL * connection;
  MYSQL_RES * resource;
  MYSQL_ROW row;
  char * server = "localhost";
  char * user = "root";
  char * password = "i78y6zbgfhla";
  char * database = "travel_through_germany";
  
  connection = mysql_init(NULL);
  
  if (!mysql_real_connect(connection, server, user, password, database, 0, NULL, 0)) {
    fprintf(stderr, "%s\n", mysql_error(connection));
    exit(1);
  }
  
  if (mysql_query(connection, "show tables")) {
    fprintf(stderr, "%s\n", mysql_error(connection));
    exit(1);
  }
  
  resource = mysql_use_result(connection);

  printf("MySQL Tables in mysql database:\n");
  while ((row = mysql_fetch_row(resource)) != NULL)
  {
    printf("%s \n", row[0]);
  }

  mysql_free_result(resource);
  mysql_close(connection);
  
  return 0;
}
