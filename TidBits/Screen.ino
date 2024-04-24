// Images
#include "introPic.h"
#include "sunrisePic.h"
#include "sunsetPic.h"
#include "firstCatPic.h"
#include "secondCatPic.h"
#include "thirdCatPic.h"

// Screen Libraries
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#define i2c_Address 0x3c //initialize with the I2C addr 0x3C Typically eBay OLED's
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET -1   //   QT-PY / XIAO
Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void initDisplay(){
  display.begin(i2c_Address, true);
  display.clearDisplay();
  display.display();
  display.setRotation(0);
}

void showIntro(){
  display.drawBitmap(20, 0, firstCatPic, 128, 64, SH110X_WHITE);
  display.setCursor(10, 48);
  display.setTextWrap(true);
  display.setTextSize(2);
  display.setTextColor(SH110X_WHITE);
  display.print("TidBits");

  display.display();
  delay(3000);
}

void showNewFact(){
  //display.drawBitmap(0, 0, sunrisePic, 128, 64, SH110X_WHITE);
  display.setCursor(10, 10);
  display.setTextWrap(true);
  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE, SH110X_BLACK);
  Serial.println(catfact);
  display.print(catfact);
  display.display();
}

void showSecondCatPic() {
  display.clearDisplay();
  if (showSecondCatPic) {
    display.drawBitmap(0, 0, secondCatPic, 128, 64, SH110X_WHITE);
  } else {
    display.drawBitmap(0, 0, thirdCatPic, 128, 64, SH110X_WHITE);
  }
  display.display();
}

//void showSunset(){
//  display.drawBitmap(0, 0, sunsetPic, 128, 64, SH110X_WHITE);
//  display.setCursor(0, 0);
//  display.setTextWrap(true);
//  display.setTextSize(1);
//  display.setTextColor(SH110X_WHITE, SH110X_BLACK);
//  display.print("sunset");
//  display.display();
//}

//int sunX = 32;  int sunSpeedY = 1;
//int sunY = 32;  int sunSpeedX = 1;

//void showSleep(){
//  sunX += sunSpeedX;
//  sunY += sunSpeedY;
//  display.drawCircle(sunX, sunY, 5, SH110X_WHITE);
//  if(sunX < 0 || sunX > 128){sunSpeedX = -sunSpeedX;}
//  if(sunY < 0 || sunY > 64){sunSpeedY = -sunSpeedY;}
//  display.display();
//}

void showSleep(){  //written by chatGPT
  // Define cat face size
  const int catWidth = 32;
  const int catHeight = 32;
  
  // Define initial position and speed of the cat face
  static int catX = 0;
  static int catY = 0;
  static int catSpeedX = 1;
  static int catSpeedY = 1;

  // Update cat face position
  catX += catSpeedX;
  catY += catSpeedY;

  // Check bounds and reverse direction if necessary
  if (catX < 0 || catX > SCREEN_WIDTH - catWidth) {
    catSpeedX = -catSpeedX;
  }
  if (catY < 0 || catY > SCREEN_HEIGHT - catHeight) {
    catSpeedY = -catSpeedY;
  }

  // Clear previous frame
  display.clearDisplay();

  // Draw cat face
  // Head
  display.fillCircle(catX + catWidth / 2, catY + catHeight / 2, catWidth / 2, SH110X_WHITE);

  // Ears (Flipped Triangles)
  display.fillTriangle(catX + catWidth / 4, catY - 3, catX + catWidth / 4 - 6, catY + 7, catX + catWidth / 4 + 6, catY + 7, SH110X_WHITE); // Left ear
  display.fillTriangle(catX + 3 * catWidth / 4, catY - 3, catX + 3 * catWidth / 4 - 6, catY + 7, catX + 3 * catWidth / 4 + 6, catY + 7, SH110X_WHITE); // Right ear

  // Eyes
  display.fillCircle(catX + catWidth / 3, catY + catHeight / 2, 3, SH110X_BLACK);
  display.fillCircle(catX + 2 * catWidth / 3, catY + catHeight / 2, 3, SH110X_BLACK);

  // Nose (Triangle)
  display.fillTriangle(catX + catWidth / 2, catY + catHeight / 2 + 6, catX + catWidth / 2 - 3, catY + catHeight / 2 + 2, catX + catWidth / 2 + 3, catY + catHeight / 2 + 2, SH110X_BLACK);

  // Mouth (Circle)
  display.fillCircle(catX + catWidth / 2, catY + catHeight / 2 + 9, 2, SH110X_BLACK);

  // Update display
  display.display();

  // Delay to control animation speed
  delay(50);
}











void clearDisplay(){display.clearDisplay();}