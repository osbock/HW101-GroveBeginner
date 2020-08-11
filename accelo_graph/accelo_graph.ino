#include <Adafruit_NeoPixel.h>
#include "LIS3DHTR.h"
#include <Wire.h>
LIS3DHTR<TwoWire> LIS(I2C_MODE);//IIC
#define WIRE Wire
#define LED 4
#define BUZZER 5
#define BUTTON 6
#define ROTARY A0
#define LIGHT A6
#define SOUND A2
#define DHTPIN 3
#define LED_PIN    3
// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 15
// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)

  Serial.begin(115200);
  LIS.begin(WIRE); //IIC init
  delay(100);
  LIS.setOutputDataRate(LIS3DHTR_DATARATE_50HZ);
}

void loop() {
  int xlevel = (int)(LIS.getAccelerationX() *1023.0);
  int LEDLevel = map(xlevel,-1023,1023,0,14);

  strip.clear();
  for (int i =0; i < LEDLevel; i++){
    strip.setPixelColor(i,strip.Color(255,0,0));
    strip.show();
  }
 

}
