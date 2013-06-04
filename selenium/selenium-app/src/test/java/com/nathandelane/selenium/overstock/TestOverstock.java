package com.nathandelane.selenium.overstock;

import org.junit.Test;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.firefox.FirefoxDriver;

public class TestOverstock {

  @Test
  public void testOstk() {
    final WebDriver driver = new FirefoxDriver();
    driver.get("http://www.overstock.com/");

    System.out.println("Page title is: " + driver.getTitle());

    driver.quit();
  }

}
