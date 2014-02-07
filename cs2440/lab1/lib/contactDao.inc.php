<?php

/**
 * Author: Nathan Lane
 * Class: CSIS-2440-002
 * Description:
 * Name: contactDao.inc.php
 *   This is a script containing Data Access functions for manipulating contacts.
 */

require_once (dirname(__FILE__) . '/dbConnection.inc.php');

define('ADD_PERSON_QUERY', 'insert into people (ppl_first_name, ppl_last_name, ppl_active, ppl_address1, ppl_address2, ppl_phone, ppl_city, ppl_stt_code, ppl_zip_code, ppl_date_created, ppl_date_updated) values (?, ?, 1, ?, ?, ?, ?, ?, ?, now(), now())');
define('SEARCH_PERSON_QUERY', 'select ppl_id, ppl_first_name, ppl_last_name, ppl_address1, ppl_address2, ppl_phone, ppl_city, ppl_stt_code, ppl_zip_code from people where ');
define('UPDATE_PERSON_QUERY', 'update people set ppl_first_name = ?, ppl_last_name = ?, ppl_address1 = ?, ppl_address2 = ?, ppl_phone = ?, ppl_city = ?, ppl_stt_code = ?, ppl_zip_code = ?, ppl_date_updated = now() where ppl_id = ?');

/**
 * Adds a new contact.
 */
function addContact($firstName, $lastName, $phone, $addressLine1, $addressLine2, $city, $state, $zip) {
  $connection = getConnection();
  $personId = 0;
  
  if (isset($connection)) {
    $firstName = $connection->escape_string($firstName);
    $lastName = $connection->escape_string($lastName);
    $phone = $connection->escape_string($phone);
    $addressLine1 = $connection->escape_string($addressLine1);
    $addressLine2 = $connection->escape_string($addressLine2);
    $city = $connection->escape_string($city);
    $state = $connection->escape_string($state);
    $zip = $connection->escape_string($zip);

    $addPersonStatement = $connection->prepare(ADD_PERSON_QUERY);
    $addPersonStatement->bind_param('ssssssss', $firstName, $lastName, $addressLine1, $addressLine2, $phone, $city, $state, $zip);
    $addPersonStatement->execute();

    $personId = $connection->insert_id;

    if ($personId == 0) {
      echo "<div class=\"fail\">Failure adding record.</div>";
    } else {
      echo "<div class=\"success\">Successfully added record.</div>";
    }

    $addPersonStatement->free_result();

    closeConnection($connection);
  }

  return $personId;
}

/**
 * Searches for an existing contact.
 */
function queryContact($firstName, $lastName, $phone, $addressLine1, $addressLine2, $city, $state, $zip) {
  $connection = getConnection();
  $whereClause = '';
  $searchResults = array();

  if (isset($connection)) {
    $whereClause .= "ppl_first_name like '%" . $connection->escape_string($firstName) . "%'";
    $whereClause .= " and ";
    $whereClause .= "ppl_last_name like '%" . $connection->escape_string($lastName) . "%'";
    $whereClause .= " and ";
    $whereClause .= "ppl_phone like '%" . $connection->escape_string($phone) . "%'";
    $whereClause .= " and ";
    $whereClause .= "ppl_address1 like '%" . $connection->escape_string($addressLine1) . "%'";
    $whereClause .= " and ";
    $whereClause .= "ppl_address2 like '%" . $connection->escape_string($addressLine2) . "%'";
    $whereClause .= " and ";
    $whereClause .= "ppl_city like '%" . $connection->escape_string($city) . "%'";
    $whereClause .= " and ";
    $whereClause .= "ppl_stt_code like '%" . $connection->escape_string($state) . "%'";
    $whereClause .= " and ";
    $whereClause .= "ppl_zip_code like '%" . $connection->escape_string($zip) . "%'";

    $query = SEARCH_PERSON_QUERY.$whereClause;
    $result = $connection->query($query);

    while ($row = $result->fetch_assoc()) {
      $record = array();
      $record['firstName'] = $row['ppl_first_name'];
      $record['lastName'] = $row['ppl_last_name'];
      $record['addressLine1'] = $row['ppl_address1'];
      $record['addressLine2'] = $row['ppl_address2'];
      $record['phone'] = $row['ppl_phone'];
      $record['city'] = $row['ppl_city'];
      $record['state'] = $row['ppl_stt_code'];
      $record['zip'] = $row['ppl_zip_code'];

      $searchResults[$row['ppl_id']] = $record;
    }

    $result->free();

    if (count($searchResults) == 0) {
      echo "<div class=\"info\">No records found matching criteria.</div>";
    }

    closeConnection($connection);
  }

  return $searchResults;
}

/**
 * This function updates an existing contact.
 */
function updateContact($pplId, $firstName, $lastName, $phone, $addressLine1, $addressLine2, $city, $state, $zip) {
  $connection = getConnection();
  $affectedRows = 0;

  if (isset($connection)) {
    $pplId = $connection->escape_string($pplId);
    $firstName = $connection->escape_string($firstName);
    $lastName = $connection->escape_string($lastName);
    $phone = $connection->escape_string($phone);
    $addressLine1 = $connection->escape_string($addressLine1);
    $addressLine2 = $connection->escape_string($addressLine2);
    $city = $connection->escape_string($city);
    $state = $connection->escape_string($state);
    $zip = $connection->escape_string($zip);

    $updatePersonStatement = $connection->prepare(UPDATE_PERSON_QUERY);
    $updatePersonStatement->bind_param('ssssssssi', $firstName, $lastName, $addressLine1, $addressLine2, $phone, $city, $state, $zip, $pplId);
    $updatePersonStatement->execute();

    $affectedRows = $connection->affected_rows;

    if ($affectedRows == -1) {
      echo "<div class=\"fail\">Failure updating record.</div>";
    } else {
      echo "<div class=\"success\">Successfully updated record.</div>";
    }

    $updatePersonStatement->free_result();

    closeConnection($connection);
  }

  return $personId;
}

?>
