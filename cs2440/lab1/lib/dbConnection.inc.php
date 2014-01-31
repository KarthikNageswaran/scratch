<?php

/**
 * dbConnection.php
 *
 * This file contains functions for opening and closing a connection.
 */

require ('data/static.inc.php');

/**
 * getConnection
 * 
 * Returns a new mysqli object.
 **/
function getConnection() {
  $connection = new mysqli('localhost', 'root', 'i78y6zbgfhla', 'nathanlane');

  return $connection;
}

/**
 * closeConnection
 *
 * Closes an open mysqli connection object.
 *
 * @param resource $connection
 **/
function closeConnection($connection) {
  if ($connection != null) {
    $connection->close();
  }
}

?>
