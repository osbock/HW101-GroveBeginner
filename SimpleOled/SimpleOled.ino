#include <U8g2lib.h>
#include <Wire.h>
U8X8_SSD1306_128X64_NONAME_HW_I2C u8x8(U8G2_R2, /* reset=*/U8X8_PIN_NONE);
void setup(void) {
  u8x8.begin();
  u8x8.setFlipMode(true);
}
void loop(void) {
  u8x8.setFont(u8x8_font_chroma48medium8_r);
  u8x8.drawString(0,1,"Hello World!");
}
