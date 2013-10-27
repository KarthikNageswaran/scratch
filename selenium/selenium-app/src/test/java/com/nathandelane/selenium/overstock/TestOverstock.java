package com.nathandelane.selenium.overstock;

import org.junit.Test;

import com.nathandelane.selenium.WebDriverFactory;

public class TestOverstock {

  @Test
  public void testOstk() throws InterruptedException, NoSuchFieldException, SecurityException {
    final LoginPage loginPage = new LoginPage();
    loginPage.setSignInEmailAddress("somebody.somewhere@gmail.com");

    WebDriverFactory.quit();
  }

}
