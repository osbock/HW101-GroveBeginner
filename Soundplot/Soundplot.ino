#define LED 4
#define BUZZER 5
#define BUTTON 6
#define ROTARY A0
#define LIGHT A6
#define SOUND A2
#define DHTPIN 3
 void setup() {
  Serial.begin(115200);

}
#define QUIET 200
void loop() {
  int reading = analogRead(SOUND);
  Serial.println(reading);

}
