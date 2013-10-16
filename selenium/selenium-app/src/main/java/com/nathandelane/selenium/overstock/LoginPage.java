package com.nathandelane.selenium.overstock;

import org.openqa.selenium.WebElement;

import com.nathandelane.selenium.FindByCssSelector;

public class LoginPage extends OverstockPage {

  @FindByCssSelector("input#EmailAddress2")
  private WebElement signInEmailAddress;

  public LoginPage() {
    super("https://www.overstock.com/myaccount");
  }

  public void setSignInEmailAddress(String emailAddress) throws NoSuchFieldException, SecurityException {
    signInEmailAddress.sendKeys(emailAddress);
  }

}
