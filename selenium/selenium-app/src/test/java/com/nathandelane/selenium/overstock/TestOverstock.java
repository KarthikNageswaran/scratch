package com.nathandelane.selenium.overstock;

import org.junit.Test;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.firefox.FirefoxDriver;
import org.openqa.selenium.interactions.Actions;

public class TestOverstock {

  @Test
  public void testOstk() throws InterruptedException {
    final FirefoxDriver driver = new FirefoxDriver();
    driver.get("http://www.overstock.com/");

    System.out.println("Page title is: " + driver.getTitle());

    final WebElement womensMenu = driver.findElementByCssSelector(".womensmenu");

    System.out.println(womensMenu.isDisplayed());
//    womensMenu.click();

    final Actions builder = new Actions(driver);
    builder.moveToElement(womensMenu).perform();

    System.out.println("Page title is: " + driver.getTitle());

    Thread.sleep(5000);

    driver.quit();
  }

}
