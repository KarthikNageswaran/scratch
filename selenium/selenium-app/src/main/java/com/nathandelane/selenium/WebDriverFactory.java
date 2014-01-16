package com.nathandelane.selenium;

import org.openqa.selenium.chrome.ChromeDriver;
import org.openqa.selenium.remote.RemoteWebDriver;

public final class WebDriverFactory {

  private static RemoteWebDriver INSTANCE;

  public static RemoteWebDriver getWebDriver() {
    if (INSTANCE == null) {
      synchronized(WebDriverFactory.class) {
        if (INSTANCE == null) {
          INSTANCE = new ChromeDriver();
        }
      }
    }

    return INSTANCE;
  }

  public static void quit() {
    INSTANCE.quit();
  }

  private WebDriverFactory() {}

}
