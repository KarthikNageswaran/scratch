<?php

/**
 * contactDao.php
 *
 * This is a library containing data access functions.
 */

require_once (dirname(__FILE__) . '/dbConnection.inc.php');

$ADD_PERSON_QUERY = 'insert into people (ppl_first_name, ppl_last_name, ppl_active, ppl_address1, ppl_address2, ppl_phone, ppl_city, ppl_stt_code, ppl_zip_code, ppl_date_created, ppl_date_updated) values (?, ?, ?, ?, ?, ?, ?, ?, ?, now(), now())';
$DELETE_CONTACT_INFO_QUERY = 'update contact_info set cti_active = 0 where cti_id = ?';
$DELETE_PERSON_QUERY = 'update people set ppl_active = 0 where ppl_id = ?';

/**
 * Adds a new contact.
 */
function addContact($firstName, $lastName, $phone, $addressLine1, $addressLine2, $city, $state, $zip) {
  $connection = getConnection();
  $personId = 0;
  
  if (isset($connection)) {
    $addPersonStatement = $connection->prepare($ADD_PERSON_QUERY);
    $addPersonStatement->bind_param('s', $firstName);
    $addPersonStatement->bind_param('s', $lastName);
    $addPersonStatement->bind_param('s', $personId);
    $addPersonStatement->bind_param('s', $addressLine1);
    $addPersonStatement->bind_param('s', $addressLine2);
    $addPersonStatement->bind_param('s', $phone);
    $addPersonStatement->bind_param('s', $city);
    $addPersonStatement->bind_param('s', $state);
    $addPersonStatement->bind_param('s', $zip);   
    $addPersonStatement->execute();

    $personId = $connection->insert_id;

    $addPersonStatement->free_result();

    closeConnection  ($connection);
  }

  return $personId;
}

?>
