#define LED 4
#define BUZZER 5
#define BUTTON 6
#define ROTARY A0
#define LIGHT A6
#define SOUND A2
#define DHTPIN 3
 void setup() {
  pinMode(LED,OUTPUT);

}

void loop() {
  int delayTime = analogRead(ROTARY);
  digitalWrite(LED, HIGH);
  delay(delayTime);
  digitalWrite(LED,LOW);
  delay(delayTime);
}
