<?php

/**
 * contactDao.php
 *
 * This is a library containing data access functions.
 */

require ('dbConnection.php');

$ADD_PERSON_QUERY = 'insert into people (first_name, last_name, date_created, date_updated) values (?, ?, now(), now())';
$GET_PERSON_ID_QUERY = 'select ppl_id from people where first_name = ? and last_name = ?';
$ADD_CONTACT_INFO_QUERY = 'insert into contact_info (cti_ppl_id, cti_address1, cti_address2, cti_phone, cti_city, cti_stt_code, cti_zip_code, cti_date_created, cti_date_updated) values (?, ?, ?, ?, ?, ?, ?, ?, now(), now())';
$DELETE_CONTACT_INFO_QUERY = 'update contact_info set cti_active = 0 where cti_id = ?';
$DELETE_PERSON_QUERY = 'update people set ppl_active = 0 where ppl_id = ?';

/**
 *
 */
function addContact($firstName, $lastName, $phone, $addressLine1, $addressLine2, $city, $state, $zip) {
  $connection = getConnection();
  $personId = 0;
  
  if ($connection != null) {
    $addPersonStatement = $connection->prepare($ADD_PERSON_QUERY);
    $addPersonStatement->bind_param('s', $firstName);
    $addPersonStatement->bind_param('s', $lastName);
    $addPersonStatement->execute();
    $addPersonStatement->free_result();

    $getPersonIdStatement = $connection->prepare($GET_PERSON_ID_QUERY);
    $getPersonIdStatement->bind_param('s', $firstName);
    $getPersonIdStatement->bind_param('s', $lastName);
    $getPersonIdStatement->execute();
    $getPersonIdStatement->bind_result($personId);

    while ($getPersonIdStatement->fetch()) {
      $addContactInfoStement = $connection->prepare($ADD_CONTACT_INFO_QUERY);
      $addContactInfoStement->bind_param('s', $personId);
      $addContactInfoStement->bind_param('s', $addressLine1);
      $addContactInfoStement->bind_param('s', $addressLine2);
      $addContactInfoStement->bind_param('s', $phone);
      $addContactInfoStement->bind_param('s', $city);
      $addContactInfoStement->bind_param('s', $state);
      $addContactInfoStement->bind_param('s', $zip);   
      $addContactInfoStement->execute();
      $addContactInfoStement->free_result();
    }

    closeConnection  ($connection);
  }

  return $personId;
}

?>
