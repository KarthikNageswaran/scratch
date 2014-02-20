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
 *   - Create a submit for update/create/search
 *     - These submits will lead the form to a 
 *       response page (named what you wish)
 *   - Create a response page that will:
 *     - Display the search results
 *     - Update a record
 *     - Create a new record
 *
 *  For an example go to http://csis02.slcc.edu/dhunter3/Index.htm
 */

?>
<!DOCTYPE html>
<html>
  <head>
    <meta content="text/html; charset=utf-8" http-equiv="content-type"/>
    <title>Contact Book | Nathan Lane CSIS-2440-002-Sp14</title>
    <link rel="stylesheet" href="css/contact-book.css" />
    <script src="//ajax.googleapis.com/ajax/libs/jquery/1.10.2/jquery.min.js"></script>
  </head>
  <body>
<?php

require_once (dirname(__FILE__) . '/_index.inc.php');

global $queryResults;

?>
    <div id="root">
      <div id="formContainer">
        <h1>Contact Book</h1>
        <form id="contactForm" name="contactForm" method="post" action="index.php">
          <input name="ppl_id" id="ppl_id" type="hidden" value="" />
          <fieldset>
            <div class="validationMessage">These fields are required to create a new contact.</div>
            <div class="searchInfoMessage">Search using any field - partial values allowed - empty form returns all records.</div>
          </fieldset>
          <fieldset>
            <label class="requiredField" for="firstName">First Name:</label>
            <input name="firstName" id="firstName" maxlength="30" type="text" />
            <label class="requiredField" for="lastName">Last Name:</label>
            <input name="lastName" id="lastName" maxlength="30" type="text" />
          </fieldset>
          <fieldset>
            <label class="requiredField" for="phone">Phone Number:</label>
            <input name="phone" id="phone" maxlength="10" type="text" />
          </fieldset>
          <fieldset>
            <label class="requiredField" for="addressLine1">Address Line 1:</label>
            <input name="addressLine1" id="addressLine1" maxlength="32" type="text" />
            <label for="addressLine2">Address Line 2:</label>
            <input name="addressLine2" id="addressLine2" maxlength="32" type="text" />
            <label class="requiredField" for="city">City:</label>
            <input name="city" id="city" maxlength="45" type="text" />
            <label class="requiredField" for="state">State:</label>
            <select id="state" name="state">
              <option value="">-- Select State --</option>
<?php

foreach ($states as $stateName => $stateCode) {

?>
              <option value="<?php echo "$stateCode"; ?>"><?php echo "$stateCode - $stateName"; ?></option>
<?php

}

?>
            </select>
            <label class="requiredField" for="zip">ZIP Code:</label>
            <input name="zip" id="zip" maxlength="10" type="text" />
          </fieldset>
          <fieldset>
            <input type="submit" name="submitButton" id="createButton" value="Create Contact" onclick="return formIsValidForCreation()"/>
            <input type="submit" name="submitButton" id="searchButton" value="Search Contacts" onclick="return formIsValidForSearch()" title="Click Search with no critera to get all records."/>
            <input type="submit" name="submitButton" id="updateButton" value="Update Contact" onclick="return formIsValidForUpdate()" disabled title="Search for a contact to update."/>
            <input type="reset" name="resetButton" id="resetButton" value="Clear Form" onclick="javascript: clearForm();"/>
          </fieldset>
        </form>
      </div>
      <div id="resultsContainer">
        <table id="searchResultsTable">
          <thead>
            <tr>
              <th>First Name</th>
              <th>Last Name</th>
              <th>State</th>
              <th>ZIP Code</th>
              <th></th>
            </tr>
          </thead>
          <tbody>
<?php

foreach ($queryResults as $key => $row) {
  
?>
            <tr>
              <td><?php echo $row['firstName'];  ?></td>
              <td><?php echo $row['lastName']; ?></td>
              <td><?php echo $row['state']; ?></td>
              <td><?php echo $row['zip']; ?></td>
              <td class="updateLinkCell">
                <a href="javascript: fillForm(<?php echo $key.",'".$row['firstName']."','".$row['lastName']."','".$row['phone']."','".$row['addressLine1']."','".$row['addressLine2']."','".$row['city']."','".$row['state']."','".$row['zip']."'"; ?>);">View or Update Record</a>
              </td>
            </tr>
<?php

}

?>
          </tbody>
        </table>
      </div>
    </div>
    <noscript>
      <div id="noJavascriptCovering">
        <div class="message">
          <h1>This Site Requires JavaScript to be Enabled</h1>
          <p>
            This website uses modern web technologies, including CSS3, and JavaScript, which are required 
            to make it perform and operate as expected.
          </p>
          <p>
            Please enable JavaScript on your browser.
          </p>
          <p>
            If you are unsure how to enable JavaScript on your browser please consult your browser vendor's documentation - usually there is a website for your browser, or google "how to turn on JavaScript in &lt;browser-name&gt;."
          </p>
          <p>
            Thank you.
          </p>
        </div>
      </div>
    </noscript>
    <script type="text/javascript">
      function fillForm(ppl_id, firstName, lastName, phoneNumber, addressLine1, addressLine2, city, state, zipCode) {
        $("#ppl_id").val(ppl_id);
        $("#firstName").val(firstName);
        $("#lastName").val(lastName);
        $("#phone").val(phoneNumber);
        $("#addressLine1").val(addressLine1);
        $("#addressLine2").val(addressLine2);
        $("#city").val(city);
        $("#state").val(state);
        $("#zip").val(zipCode);
        
        if ($.trim($("#ppl_id").val()).length != 0) {
          $("#updateButton").prop("disabled", false);
          $("#createButton").prop("disabled", true);
        }
        else {
          $("#updateButton").prop("disabled", true);
          $("#createButton").prop("disabled", false);
        }
      }

      function formIsValid() {
        var formIsValid = true;
        
        $(":text").each(function(index) {
          var val = $(this).val();
          
          if ($(this).attr("id") != "addressLine2" && $.trim(val).length == 0) {
            $(this).attr("class", "invalidField");
            
            formIsValid = false;
          } else {
            $(this).attr("class", "");
          }
        });
        
        if ($.trim($("#state").val()).length == 0) {
          $("#state").attr("class", "invalidField");
        } else {
          $(this).attr("class", "");
        }
        
        return formIsValid;
      }

      function formIsValidForCreation() {
        return formIsValid();
      }

      function formIsValidForSearch() {
        return true;
      }

      function formIsValidForUpdate() {
        return formIsValid();
      }
      
      function clearForm() {
        fillForm("", "", "", "", "", "", "", "", "");

        $("#updateButton").prop("disabled", true);
        $("#createButton").prop("disabled", false);
    
        return true;
      }
    </script>
  </body>
</html>
