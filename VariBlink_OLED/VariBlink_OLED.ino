#include <U8g2lib.h>
#include <Wire.h>

#define LED 4
#define BUZZER 5
#define BUTTON 6
#define ROTARY A0
#define LIGHT A6
#define SOUND A2
#define DHTPIN 3

U8X8_SSD1306_128X64_NONAME_HW_I2C u8x8(/* reset=*/U8X8_PIN_NONE);

void setup() {
  // OLED Setup
  u8x8.begin();
  u8x8.setFlipMode(true);
  u8x8.setFont(u8x8_font_chroma48medium8_r);
  
  // LED Output
  pinMode(LED,OUTPUT);
}

void loop() {
  int delayTime = analogRead(ROTARY);
  u8x8.drawString(0,0,"Delay Time (ms):");
  u8x8.clearLine(1);
  u8x8.setCursor(0, 1);
  u8x8.print(delayTime);
  digitalWrite(LED, HIGH);
  delay(delayTime);
  digitalWrite(LED,LOW);
  delay(delayTime);
}
