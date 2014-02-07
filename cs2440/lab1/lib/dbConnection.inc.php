<?php

/**
 * dbConnection.inc.php
 *
 * This file contains functions for opening and closing a connection.
 */

require_once(dirname(__FILE__) . '/data/static.inc.php');

/**
 * getConnection
 * 
 * Returns a new mysqli object.
 **/
function getConnection() {
  global $dbCredentials;

  $connection = new mysqli($dbCredentials['hostName'], $dbCredentials['userName'], $dbCredentials['password'], $dbCredentials['dbName']);

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
