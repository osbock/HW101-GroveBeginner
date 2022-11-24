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
  plotInRange(reading);
}

#define PLOT_MIN 0
#define PLOT_MAX 1000
// Plots an upper/lower bound value to stablize the plot output
void plotInRange(int plotValue) {
  Serial.print(PLOT_MIN);  // lower-bound value
  Serial.print(" ");
  Serial.print(PLOT_MAX);  // upper-bound value
  Serial.print(" ");
  Serial.println(plotValue);  // actual plotted value
}
