<?php

/**
 * Author: Nathan Lane
 * Class: CSIS-2440-002
 * Description:
 * Name: statesDao.inc.php
 *   Data access object used to retrieve states from the database.
 */

require_once (dirname(__FILE__) . '/dbConnection.inc.php');

define('GET_STATES_QUERY', 'select stt_code, stt_name from states order by stt_code asc');

/**
 * Query all states - names and state abbreviations - from the database.
 */
function queryStates() {
  $connection = getConnection();
  $statesArray = array();

  if (isset($connection)) {
    $stateCode = '';
    $stateName = '';
    $statesStatement = $connection->prepare(GET_STATES_QUERY);
    $statesStatement->execute();

    $statesStatement->bind_result($stateCode, $stateName);

    while ($statesStatement->fetch()) {
      $statesArray[$stateName] = $stateCode;
    }

    $statesStatement->free_result();

    closeConnection($connection);
  }

  return $statesArray;
}

?>
