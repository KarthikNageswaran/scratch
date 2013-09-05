package com.nathandelane.selenium.overstock;

import java.util.List;

import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JPasswordField;

import org.junit.Test;
import org.openqa.selenium.Alert;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.firefox.FirefoxDriver;
import org.openqa.selenium.support.ui.Select;

import com.google.common.collect.Lists;

public class TestOverstockOutlook {

  private static final String HTTPS_OUTLOOK_OVERSTOCK_COM = JOptionPane.showInputDialog("Enter URL for Mail");

  private static final List<Integer> FOLDERS_TO_CLEAN_OUT = Lists.newArrayList(
    4, // Deleted Items
    11, // Crons
    4, // Deleted Items
    13, // Jenkins
    4, // Deleted Items
    14, // Logwatch
    4, // Deleted Items
    15, // Oh No
    4, // Deleted Items
    17, // Production Alerts
    4, // Deleted Items
    18, // Splunk
    4, // Deleted Items
    19, // Usage
    4, // Deleted Items
    21, // Stage Alerts
    4, // Deleted Items
    28, // Splunk
    4, // Deleted Items
    29, // Splunk 249
    4, // Deleted Items
    79, // Jira
    4, // Deleted Items
    80, // Spec Processor
    4, // Deleted Items
    96, // Carrier Code Not Found
    4, // Deleted Items
    103, // Subversion
    4 // Deleted Items
      );

  @Test
  public void testOstkMailDeleteUnwantedMail() throws InterruptedException {
    final FirefoxDriver driver = new FirefoxDriver();
    driver.get(HTTPS_OUTLOOK_OVERSTOCK_COM);

    try {
      Thread.sleep(3000);

      System.out.println("Page title is: " + driver.getTitle());

      try {
        final WebElement logoutLink = driver.findElementByCssSelector("#lo");

        if (logoutLink.isDisplayed()) {
          logoutLink.click();

          final WebElement clickHereToContinueWorkingLink = driver
              .findElementByLinkText("Click here to continue working.");

          if (clickHereToContinueWorkingLink.isDisplayed()) {
            driver.get(HTTPS_OUTLOOK_OVERSTOCK_COM);
          }
        }
      }
      catch (Exception e) {
        System.out.println("Apparently we aren't logged in, so good.");
      }

      final WebElement useLightVersionCheckbox = driver.findElementByCssSelector("#chkBsc");

      if (useLightVersionCheckbox.isDisplayed()) {
        if (!useLightVersionCheckbox.isSelected()) {
          useLightVersionCheckbox.click();
        }

        final WebElement userNameField = driver.findElementByCssSelector("#username");
        final WebElement password = driver.findElementByCssSelector("#password");

        userNameField.sendKeys(JOptionPane.showInputDialog("Please enter your user name."));

        final JPanel panel = new JPanel();
        final JLabel label = new JLabel("Enter a password:");
        final JPasswordField pass = new JPasswordField(10);
        panel.add(label);
        panel.add(pass);
        pass.requestFocusInWindow();
        String[] options = new String[] { "OK", "Cancel" };
        int option = JOptionPane.showOptionDialog(null, panel, "The title", JOptionPane.NO_OPTION,
          JOptionPane.PLAIN_MESSAGE, null, options, options[0]);
        if (option == 0) // pressing OK button
        {
          final char[] passwordValue = pass.getPassword();
          password.sendKeys(new String(passwordValue));

          final WebElement submitButton = driver.findElementByCssSelector(".btn");
          submitButton.click();

          final WebElement logoutLink = driver.findElementByCssSelector("#lo");

          if (logoutLink.isDisplayed()) {
            System.out.println("Logged in successfully.");

            final WebElement selectFoldersLink = driver.findElementByCssSelector("#lnkBrwsAllFldrs");

            if (selectFoldersLink.isDisplayed()) {
              selectFoldersLink.click();

              final WebElement folderSelectList = driver.findElementByCssSelector("#selbrfld");

              if (folderSelectList.isDisplayed()) {
                for (Integer nextFolderIndex : FOLDERS_TO_CLEAN_OUT) {
                  new Select(driver.findElementByCssSelector("#selbrfld")).selectByIndex(nextFolderIndex);

                  final WebElement gotoFolderLink = driver.findElementByCssSelector("#lnkGotoFldr");

                  if (gotoFolderLink.isDisplayed()) {
                    gotoFolderLink.click();

                    int numRows = driver.findElementsByCssSelector(".lvw input[type='checkbox']").size();

                    if (numRows > 1) {
                      do {
                        final WebElement selectAllCheckbox = driver
                            .findElementByCssSelector(".chd > input[title='Select All Items']");

                        if (selectAllCheckbox.isDisplayed()) {
                          selectAllCheckbox.click();

                          final WebElement deleteButton = driver.findElementByCssSelector("#lnkHdrdelete");

                          if (deleteButton.isDisplayed()) {
                            deleteButton.click();

                            Thread.sleep(500);

                            try {
                              Alert javascriptAlert = driver.switchTo().alert();
                              javascriptAlert.accept();
                            }
                            catch (Exception e) {
                              // Do nothing - no alert found.
                            }
                          }
                        }

                        Thread.sleep(1000);

                        numRows = driver.findElementsByCssSelector(".lvw tbody tr").size();
                      }
                      while (numRows > 1 && numRows != 4 && numRows != 0);
                    }
                  }

                  Thread.sleep(3000);
                }
              }
            }
          }
        }
      }

      // final Actions builder = new Actions(driver);
      // builder.moveToElement(logoutLink).perform();
      //
      // System.out.println("Page title is: " + driver.getTitle());
      //
      // Thread.sleep(5000);
    }
    finally {
      try {
        final WebElement logoutLink = driver.findElementByCssSelector("#lo");

        if (logoutLink.isDisplayed()) {
          logoutLink.click();

          final WebElement clickHereToContinueWorkingLink = driver
              .findElementByLinkText("Click here to continue working.");

          if (clickHereToContinueWorkingLink.isDisplayed()) {
            driver.get(HTTPS_OUTLOOK_OVERSTOCK_COM);
          }
        }
      }
      catch (Exception e) {
        System.err.println("Couldn't log out - couldn't figure out how to log out..oh well.");
      }

      driver.quit();
    }
  }

}
