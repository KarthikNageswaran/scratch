<?php

/**
 * statesDao.inc.php
 *
 * Data access object used to retrieve states from the database.
 *
 * @author Nathan Lane
 */

require_once (dirname(__FILE__) . '/dbConnection.inc.php');

define('GET_STATES_QUERY', 'select stt_code, stt_name from states');

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
