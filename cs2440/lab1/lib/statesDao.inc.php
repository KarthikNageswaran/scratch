<?php

/**
 * statesDao.inc.php
 *
 * Data access object used to retrieve states from the database.
 *
 * @author Nathan Lane
 */

require (dirname(__FILE__) . '/dbConnection.inc.php');

$GET_STATES_QUERY = 'select stt_code, stt_name from states';

function queryStates() {
  $connection = getConnection();

  if (isset($connection)) {
    closeConnection($connection);
  }
}

?>
