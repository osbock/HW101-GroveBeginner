#include <U8g2lib.h>
#include <Wire.h>
#include <DHT.h>
#include <stdlib.h> // be careful, pulls in a lot.

#define DHTPIN 3
#define BUTTON 6
#define DHTTYPE DHT11

// global objects
U8X8_SSD1306_128X64_NONAME_HW_I2C u8x8(/* reset=*/U8X8_PIN_NONE);
DHT dht(DHTPIN, DHTTYPE);

//setup runs at reset
void setup(void) {
  Serial.begin(115200);
  u8x8.begin();
  u8x8.setFlipMode(true);
  Wire.begin();
  dht.begin();
}

float readTemp(){
    float temp_hum_val[2] = {0};
    // Reading temperature or humidity takes about 250 milliseconds!
    // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
    
    
    if(!dht.readTempAndHumidity(temp_hum_val)){
      return temp_hum_val[1];
    }
    else{
       Serial.println("Failed to get temprature and humidity value.");
       return (-1);
    }
}
char tempBuf[10];
bool  fahrmode = false;
void loop(void) {
  u8x8.setFont(u8x8_font_inr21_2x4_f);
  float temp = readTemp();
  if (digitalRead(BUTTON)){
    temp = (temp *9)/5 +32;
    fahrmode = true;
  }
  else
    fahrmode = false;
  dtostrf(temp,3,1,tempBuf);
  if (fahrmode)
    strcat(tempBuf, " F");
  else
    strcat(tempBuf," C");
   
  u8x8.drawString(0,0,tempBuf);
}
