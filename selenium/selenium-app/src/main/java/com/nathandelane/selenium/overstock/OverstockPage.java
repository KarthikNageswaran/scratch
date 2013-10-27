package com.nathandelane.selenium.overstock;

import java.lang.reflect.Field;

import org.openqa.selenium.By;
import org.openqa.selenium.WebElement;

import com.nathandelane.selenium.FindByCssSelector;
import com.nathandelane.selenium.WebDriverFactory;

public abstract class OverstockPage {

  protected OverstockPage(String url) {
    WebDriverFactory.getWebDriver().get(url);

    try {
      initializeFields();
    }
    catch (IllegalArgumentException e) {
      e.printStackTrace();
    }
    catch (IllegalAccessException e) {
      e.printStackTrace();
    }
  }

  protected String getTitle() {
    return WebDriverFactory.getWebDriver().getTitle();
  }

  protected WebElement getWebElement(String cssSelector) {
    return WebDriverFactory.getWebDriver().findElement(By.cssSelector(cssSelector));
  }

  protected String getCssSelector(Field field) {
    return field.getAnnotation(FindByCssSelector.class).value();
  }

  private void initializeFields() throws IllegalArgumentException, IllegalAccessException {
    for (Field nextField : this.getClass().getDeclaredFields()) {
      final FindByCssSelector cssSelectorAnnotation = nextField.getAnnotation(FindByCssSelector.class);

      if (cssSelectorAnnotation != null) {
        nextField.setAccessible(true);
        nextField.set(this, WebDriverFactory.getWebDriver().findElementByCssSelector(cssSelectorAnnotation.value()));
      }
    }
  }

}
