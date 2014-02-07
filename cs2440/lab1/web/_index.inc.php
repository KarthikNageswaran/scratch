<?php

/**
 * _index.inc.php
 *
 * This is the code-behind for the index page.
 *
 * @author Nathan Lane
 */

require (dirname(__FILE__) . '/../lib/statesDao.inc.php');
require (dirname(__FILE__) . '/../lib/contactDao.inc.php');

define('FIRST_NAME_KEY', 'firstName');
define('LAST_NAME_KEY', 'lastName');
define('PHONE_KEY', 'phoneNumber');
define('ADDRESS_LINE1_KEY', 'addressLine1');
define('ADDRESS_LINE2_KEY', 'addressLine2');
define('CITY_KEY', 'city');
define('STATE_KEY', 'state');
define('ZIP_KEY', 'zip');
define('SUBMIT_BUTTON_KEY', 'submitButton');
define('CREATE_BUTTON_VALUE', 'Create Contact');
define('UPDATE_BUTTON_VALUE', 'Update Contact');
define('SEARCH_BUTTON_VALUE', 'Search Contacts');

$states = queryStates();

function createNewUser($firstName, $lastName, $phone, $addressLine1, $addressLine2, $city, $state, $zip) {
  addContact($firstName, $lastName, $phone, $addressLine1, $addressLine2, $city, $state, $zip);
}

function queryUser($firstName, $lastName, $phone, $addressLine1, $addressLine2, $city, $state, $zip) {
}

function updateUser($firstName, $lastName, $phone, $addressLine1, $addressLine2, $city, $state, $zip) {
}

function processPostBack() {
  if (isset($_POST[SUBMIT_BUTTON_KEY])) {
    $firstName = $_POST[FIRST_NAME_KEY];
    $lastName = $_POST[LAST_NAME_KEY];
    $phone = $_POST[PHONE_KEY];
    $addressLine1 = $_POST[ADDRESS_LINE1_KEY];
    $addressLine2 = $_POST[ADDRESS_LINE2_KEY];
    $city = $_POST[CITY_KEY];
    $state = $_POST[STATE_KEY];
    $zip = $_POST[ZIP_KEY];

    if (strcmp($_POST[SUBMIT_BUTTON_KEY], CREATE_BUTTON_VALUE) == 0) {
      createNewUser($firstName, $lastName, $phone, $addressLine1, $addressLine2, $city, $state, $zip);
    }
    elseif (strcmp($_POST[SUBMIT_BUTTON_KEY], UPDATE_BUTTON_VALUE) == 0) {
      queryUser($firstName, $lastName, $phone, $addressLine1, $addressLine2, $city, $state, $zip);
    }
    elseif (strcmp($_POST[SUBMIT_BUTTON_KEY], SEARCH_BUTTON_VALUE) == 0) {
      updateUser($firstName, $lastName, $phone, $addressLine1, $addressLine2, $city, $state, $zip);
    }
  }
}

if (isset($_POST)) {
  processPostBack();
}

?>
