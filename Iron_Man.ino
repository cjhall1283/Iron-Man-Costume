#include <Adafruit_NeoPixel.h>

#define BUTTON_PIN   2    // Digital IO pin connected to the button.  This will be


#define PIXEL_PIN    6    // Digital IO pin connected to the NeoPixels.

#define PIXEL_COUNT 40

Adafruit_NeoPixel ironman = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);


void setup() {
  pinMode(BUTTON_PIN, INPUT);
  ironman.begin();
  ironman.show(); // Initialize all pixels to 'off'
}

void loop() {
  // Get current button state.
//  bool newState = digitalRead(BUTTON_PIN);
//  if (newState == HIGH) {
//    isBlastinBaddies(0);
//  } 
//  else {
//    isBlastinBaddies(1);
//  }
isBlastinBaddies(0);
delay (2000);

}

void isBlastinBaddies(int i) {
  switch(i){
  case 0: 
    fireHandCannon(ironman.Color(120, 120, 120), 180);    // Black/off
    break;
  case 1: 
    //    colorWipe(ironman.Color(255, 0, 0), 50);  // Red
    break;

  }
}

//Kill all the mother truckers
void fireHandCannon(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<ironman.numPixels(); i++) {
    ironman.setPixelColor(i, c);
  }
  ironman.show();
  //Dim the blaster from 180 to 40
  for (int brightness=120; brightness>10; brightness--) {
    for (uint16_t i=24; i<ironman.numPixels(); i++) {
      ironman.setPixelColor(i, ironman.Color(brightness, brightness, brightness));
    }
    ironman.show();
    delay (5);
  }
  delay (200);
  int abrightness = 120;
  //Turn each pixel on blaster to 180 one at a time while 
  //decreasing the brightness on the arc reactor by 5 each itme
  for(uint16_t i=24; i<ironman.numPixels(); i++) {
    abrightness-=7;
    for (uint16_t j=0; j<24; j++) {
      ironman.setPixelColor(j,ironman.Color(abrightness, abrightness, abrightness)); 
    }  
    ironman.setPixelColor(i, c);
    ironman.show();
    delay(wait);
  }
  //Increase brightness on blaster from 120 to 230
  for (int brightness=120; brightness<230; brightness++) {
    for (uint16_t i=24; i<ironman.numPixels(); i++) {
      ironman.setPixelColor(i, ironman.Color(brightness, brightness, brightness));
    }
    ironman.show();
    delay (5);
  }
  //Briefly turn off blaster
  for (uint16_t i=24; i<ironman.numPixels(); i++) {
    ironman.setPixelColor(i, ironman.Color(0,0,0));
  }
  ironman.show();
  delay (200);
  //Turn blaster on at max brightness
  for (uint16_t i=24; i<ironman.numPixels(); i++) {
    ironman.setPixelColor(i, ironman.Color(254,254,254));
  }
  ironman.show();
  delay(100);
  //Dim blaster back to base 
  for (int brightness=255; brightness>120; brightness--) {
    for (uint16_t i=24; i<ironman.numPixels(); i++) {
      ironman.setPixelColor(i, ironman.Color(brightness, brightness, brightness));
    }
    ironman.show();
    delay (5);
  }
  //Return brightness of arc reactor to base
  for (abrightness; abrightness<120; abrightness++) {
    for (uint16_t i=0; i<24; i++) {
      ironman.setPixelColor(i, ironman.Color(abrightness, abrightness, abrightness));
    }
    ironman.show();
    delay (80);
  }
 
//  uint16_t i, j;
//
//  for(j=0; j<256*20; j++) { // 5 cycles of all colors on wheel
//    for(i=0; i< 24; i++) {
//      ironman.setPixelColor(i, Wheel(((i * 256 / 24) + j) & 255));
//    }
//    for(i=24; i< 40; i++) {
//      ironman.setPixelColor(i, Wheel(((i * 256 / 16) + j) & 255));
//    }
//    ironman.show();
//    delay(20);
//  }

}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return ironman.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } 
  else if(WheelPos < 170) {
    WheelPos -= 85;
    return ironman.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  } 
  else {
    WheelPos -= 170;
    return ironman.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  }
}






