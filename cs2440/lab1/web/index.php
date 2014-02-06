<?php

/**
 * Author: Nathan Lane
 * Class: cs2440-002 Spring 2014
 * Description:
 *   PHP and MySQL Lab1
 *
 *   Address book and contact page
 *
 *   Tasks to Complete:
 *   - Create a form page with input for:
 *     - First name
 *     - Last name
 *     - Phone
 *     - Address
 *     - City
 *     - State (should be a drop-down list)
 *     - ZIP code
 *   - Create a button for update/create/search
 *     - These buttons will lead the form to a 
 *       response page (named what you wish)
 *   - Create a response page that will:
 *     - Display the search results
 *     - Update a record
 *     - Create a new record
 *
 *  For an example go to http://csis02.slcc.edu/dhunter3/Index.htm
 */

require (dirname(__FILE__) . '/_index.inc.php');

?>
<!DOCTYPE html>
<html>
  <head>
    <meta content="text/html; charset=utf-8" http-equiv="content-type"/>
    <title>Contact Book | Nathan Lane CSIS-2440-002-Sp14</title>
    <link rel="stylesheet" href="css/contact-book.css" />
  </head>
  <body>
    <div id="root">
      <form id="contactForm" name="contactForm" method="post" action="index.php">
        <fieldset>
          <input name="firstName" id="firstName" maxlength="30" />
          <input name="lastName" id="lastName" maxlength="30" />
        </fieldset>
        <fieldset>
          <input name="phone" id="phone" maxlength="10" />
        </fieldset>
        <fieldset>
          <input name="addressLine1" id="addressLine1" maxlength="32" />
          <input name="addressLine2" id="addressLine2" maxlength="32" />
          <input name="city" id="city" maxlength="45" />
          <select id="state" name="state">
<?php

foreach ($states as $stateName => $stateCode) {

?>
            <option value="<?php echo "$stateCode"; ?>"><?php echo "$stateName"; ?></option>
<?php

}

?>
          </select>
          <input name="zip" id="zip" maxlength="10" />
        </fieldset>
      </form>
    </div>
  </body>
</html>
