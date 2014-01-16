package com.nathandelane.selenium.overstock;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

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
import com.google.common.collect.Maps;

public class TestOverstockOutlook {

  private static final String HTTPS_OUTLOOK_OVERSTOCK_COM = (System.getProperty("url") == null
      ? JOptionPane.showInputDialog("Enter URL for Mail")
      : System.getProperty("url"));

  private static final Map<Integer, String> FOLDERS_TO_CLEAN_OUT = Maps.newHashMap();
  static {
//    6, // Inbox
//    4, // Deleted Items
    FOLDERS_TO_CLEAN_OUT.put(15, "Crons");
    FOLDERS_TO_CLEAN_OUT.put(16, "Deploys");
    FOLDERS_TO_CLEAN_OUT.put(17, "DevOps");
    FOLDERS_TO_CLEAN_OUT.put(18, "Jenkins");
    FOLDERS_TO_CLEAN_OUT.put(19, "Logwatch");
    FOLDERS_TO_CLEAN_OUT.put(20, "Oh No");
    FOLDERS_TO_CLEAN_OUT.put(21, "Performance");
    FOLDERS_TO_CLEAN_OUT.put(22, "Production Alerts");
    FOLDERS_TO_CLEAN_OUT.put(23, "Splunk");
    FOLDERS_TO_CLEAN_OUT.put(24, "Usage");
    FOLDERS_TO_CLEAN_OUT.put(26, "Stage Alerts");
    FOLDERS_TO_CLEAN_OUT.put(28, "Hadoop");
    FOLDERS_TO_CLEAN_OUT.put(31, "Otag");
    FOLDERS_TO_CLEAN_OUT.put(32, "Solr Evictions");
    FOLDERS_TO_CLEAN_OUT.put(33, "Splunk");
    FOLDERS_TO_CLEAN_OUT.put(34, "Splunk Test249");
    FOLDERS_TO_CLEAN_OUT.put(38, "B2C Order Monitor");
    FOLDERS_TO_CLEAN_OUT.put(83, "Jira");
    FOLDERS_TO_CLEAN_OUT.put(84, "spec processor");
    FOLDERS_TO_CLEAN_OUT.put(100, "Carrier Code Not Found");
    FOLDERS_TO_CLEAN_OUT.put(108, "Production Alerts");
    FOLDERS_TO_CLEAN_OUT.put(109, "Subversion");
//    31, // Stage Requests
//    4 // Deleted Items
  }

  private static final Map<Integer, List<String>> FROM_ADDRESSES_TO_DELETE = new HashMap<Integer, List<String>>();
  static {
    FROM_ADDRESSES_TO_DELETE.put(6, Lists.<String> newArrayList("webalert@oversto... ", "splunk@overstock... ",
      "splunksearch.sta... ", "Cron Daemon ", "nagios.stage@ove... "));
  }

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

        userNameField.sendKeys(System.getProperty("username") == null
            ? JOptionPane.showInputDialog("Please enter your user name.")
            : System.getProperty("username"));

        int option = 0;
        String passwordValue = "";
        JPanel panel = new JPanel();
        JLabel label = new JLabel("Enter a password:");
        JPasswordField pass = new JPasswordField(10);

        if (System.getProperty("password") == null) {
          panel.add(label);
          panel.add(pass);
          pass.requestFocusInWindow();
          String[] options = new String[] { "OK", "Cancel" };
          option = JOptionPane.showOptionDialog(null, panel, "The title", JOptionPane.NO_OPTION,
            JOptionPane.PLAIN_MESSAGE, null, options, options[0]);
          passwordValue = new String(pass.getPassword());
        }
        else {
          passwordValue = System.getProperty("password");
        }

        if (option == 0) { // pressing OK button
          System.out.println("Option OK was selected.");

          password.sendKeys(passwordValue);

          final WebElement submitButton = driver.findElementByCssSelector(".btn");
          submitButton.click();

          Thread.sleep(3000);

          final WebElement logoutLink = driver.findElementByCssSelector("#lo");

          if (logoutLink.isDisplayed()) {
            System.out.println("Logged in successfully.");

            final WebElement selectFoldersLink = driver.findElementByCssSelector("#lnkBrwsAllFldrs");

            if (selectFoldersLink.isDisplayed()) {
              selectFoldersLink.click();

              final WebElement folderSelectList = driver.findElementByCssSelector("#selbrfld");

              if (folderSelectList.isDisplayed()) {
                for (Map.Entry<Integer, String> nextFolderEntry : FOLDERS_TO_CLEAN_OUT.entrySet()) {
                  new Select(driver.findElementByCssSelector("#selbrfld")).selectByIndex(nextFolderEntry.getKey());

                  final List<WebElement> selectedOptions = new Select(driver.findElementByCssSelector("#selbrfld")).getAllSelectedOptions();

                  System.out.println(String.format("Selected option: %1$s, expected: %2$s", selectedOptions.get(0).getAttribute("title"), nextFolderEntry.getValue()));

                  if (selectedOptions.size() == 1 && selectedOptions.get(0).getAttribute("title").contains(nextFolderEntry.getValue())) {
                    final WebElement gotoFolderLink = driver.findElementByCssSelector("#lnkGotoFldr");

                    if (gotoFolderLink.isDisplayed()) {
                      gotoFolderLink.click();

//                    if (FROM_ADDRESSES_TO_DELETE.containsKey(nextFolderIndex)) {
//                      final List<String> fromEmailAddresses = FROM_ADDRESSES_TO_DELETE.get(nextFolderIndex);
//
//                      for (String nextEmailAddress : fromEmailAddresses) {
//                        final WebElement
//                      }
//                    }
//                    else {
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

                                numRows = driver.findElementsByCssSelector(".lvw tbody tr").size();
                              }
                            }
                          }
                          while (numRows > 1 && numRows != 4 && numRows != 0);

                          // Deleted Items Stuff
                          try {
                            new Select(driver.findElementByCssSelector("#selbrfld")).selectByIndex(4); // Deleted Items

                            final WebElement diGotoFolderLink = driver.findElementByCssSelector("#lnkGotoFldr");

                            if (diGotoFolderLink.isDisplayed()) {
                              diGotoFolderLink.click();

                              final List<WebElement> deletedItemsSelectedOptions = new Select(driver.findElementByCssSelector("#selbrfld")).getAllSelectedOptions();

                              if (deletedItemsSelectedOptions.size() == 1 && deletedItemsSelectedOptions.get(0).getAttribute("title").contains("Deleted Items")) {
                                do {
                                  final WebElement diSelectAllCheckbox = driver
                                      .findElementByCssSelector(".chd > input[title='Select All Items']");

                                  if (diSelectAllCheckbox.isDisplayed()) {
                                    diSelectAllCheckbox.click();

                                    final WebElement dIDeleteButton = driver.findElementByCssSelector("#lnkHdrdelete");

                                    if (dIDeleteButton.isDisplayed()) {
                                      dIDeleteButton.click();

                                      Thread.sleep(500);

                                      Alert javascriptAlert = driver.switchTo().alert();
                                      javascriptAlert.accept();

                                      Thread.sleep(1000);

                                      numRows = driver.findElementsByCssSelector(".lvw tbody tr").size();
                                    }
                                  }
                                }
                                while (numRows > 1 && numRows != 4 && numRows != 0);
                              }
                            }
                          }
                          catch (Exception e) {
                            // Do nothing - no alert found.
                          }

                          Thread.sleep(1000);
                        }
//                    }
                    }
                  }
                  else {
                    System.out.println("Skipped folder, because it wasn't what was expected.");
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
