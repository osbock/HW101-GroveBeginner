#include <Adafruit_NeoPixel.h>
#define LED_PIN 2
#define LED_COUNT 24
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

String inString = "";    // string to hold input

void setup() {
  Serial.begin(115200);
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)

}
 void setlimit(int val){
  for (int i =0;i < strip.numPixels(); i++)
    strip.setPixelColor(i,0);
  for (int i = 0 ; i < val; i++){
    strip.setPixelColor(i,strip.Color(255,0,0));
  }
  strip.show();
 }

void loop() {
  // Read serial input:
  while (Serial.available() > 0) {
    int inChar = Serial.read();
    if (isDigit(inChar)) {
      // convert the incoming byte to a char and add it to the string:
      inString += (char)inChar;
    }
    // if you get a newline, grab the value and display it in neopixels
    if (inChar == '\n') {
      int value = inString.toInt();
      // make sure the value is in range
      if ((value >=0) && (value <= LED_COUNT))
        setlimit(value);
      // clear the string for new input:
      inString = "";
    }
  }
}
