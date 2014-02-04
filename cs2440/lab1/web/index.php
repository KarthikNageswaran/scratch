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
  </head>
  <body>
    <div id="root">
      <select id="state" name="state">
<?php

foreach ($states as $stateName => $stateCode) {

?>
        <option value="<?php echo "$stateCode"; ?>"><?php echo "$stateName"; ?></option>
<?php

}

?>
      </select>
    </div>
  </body>
</html>
