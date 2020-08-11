#include <Adafruit_NeoPixel.h>

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
}
#define AMBIENTNOISE 380
void loop() {
  int soundlevel = analogRead(SOUND);
  Serial.println(soundlevel);
  if (soundlevel < AMBIENTNOISE)
    soundlevel = AMBIENTNOISE; // only display above ambient
  int LEDLevel = map(soundlevel,AMBIENTNOISE,1023,0,14);

  strip.clear();
  for (int i =0; i < LEDLevel; i++){
    strip.setPixelColor(i,strip.Color(255,0,0));
    strip.show();
  }
 

}
