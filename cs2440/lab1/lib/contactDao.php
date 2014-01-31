/**
 * contactDao.php
 *
 * This is a library containing data access functions.
 */

$ADD_PERSON_QUERY = "insert into people (first_name, last_name, date_created, date_updated) values (?, ?, ?, ?)";
$ADD_CONTACT_INFO_QUERY = "insert into contact_info (cti_ppl_id, cti_address1, cti_address2, cti_phone, cti_city, cti_stt_code, cti_zip_code, cti_date_created, cti_date_updated) values (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
$DELETE_CONTACT_INFO_QUERY = "update contact_info set cti_active = 0 where cti_id = ?";
$DELETE_PERSON_QUERY = "update people set ppl_active = 0 where ppl_id = ?";

/**
 * getConnection
 *
 * Returns a new mysqli object.
 */
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
 */
function closeConnection($connection) {
  if (is_resource($connection)) {
    $connection->close();
  }
}

/**
 *
 */
function addContact($firstName, $lastName, $phone, $addressLine1, $addressLine2, $city, $state, $zip) {
  $connection = getConnection();

  
}

