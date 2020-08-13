// State management enum
enum State{
  alarming,
  armed,
  disarmed
 };

State alarmState;

// The place on the board we plugged in the motion sensor
int MOTION_SENSOR_PIN = 2;
//The function that is callled when motion is detected
void motionDetected();

// The Buzzer is plugged into D5 Already, so we will use that
int BUZZER_PIN = 5;
// The frequency for the buzzer to buzz at in Hz
int buzzerFrequency = 33;
// The buzzer function
void buzzBuzzer();

// The arm/disarm button pin
int BUTTON_PIN = 6;
// the function to check the status of the button and 
void updateButtonStatus();

// Millis trackers
unsigned long prevMillis = 0;
unsigned long currentMillis;

// Locks out the button press
int LOCKOUT_FLAG = 0;
int LOCKOUT_INTERVAL = 1000;


void setup() {
  // put your setup code here, to run once:

    // Set the button to be an input for arming and disarming the alarm
    pinMode(BUTTON_PIN, INPUT);

    // Set the motion sensor that we plugged into `MOTION_SENSOR_PIN` to be an input
    pinMode(MOTION_SENSOR_PIN, INPUT);
    // Add an event trigger for the motion detector
    attachInterrupt(digitalPinToInterrupt(MOTION_SENSOR_PIN), motionDetected, HIGH);

    // Set the buzzer to an output using the pin `BUZZER_PIN`
    pinMode(BUZZER_PIN, OUTPUT);

    // Start with the alarm disarmed
    alarmState = disarmed;

    // Begin sending and recieving to/from the computer
    Serial.begin(9600);
}

void loop() {
    // Note, for simplicity state, nothing is locking out the state changes in the middle of another intterrupt. 

    // Refresh the status of the button
    updateButtonStatus();

    // Handle all the states of the alarm system
    switch(alarmState)
    {
       // IF the alarm is supposed to be going off, do the actions that an alarm system would do when going off
      case alarming:
        Serial.println("Motion Detected");
        buzzBuzzer();
        break;
      case armed:
        // We don't really care if we haven't seen anything as that's what we expect but we should indicate that we are armed by blinking
        Serial.println("Watching");
        break;
      case disarmed:
        // We probably don't have to do anything to indicate that the system is off
        Serial.println("Waiting for Activation");
        break;
    }
}

void buzzBuzzer()
{
  // Buzz the buzzer for 10ms at `buzzerFrequency` then reset the tone function using a 1ms buzz at 1+`buzzerFrequency`. This could also be done using `noTone(buzzerFrequency)` but we will stick with this method as it sounds nicer.
  tone(BUZZER_PIN, buzzerFrequency, 1000);
  tone(BUZZER_PIN, buzzerFrequency + 1, 1);
}

void motionDetected()
{
    // if the alarm was armed when motion was detected, change from armed to alarming
    if(alarmState == armed)
    {
      alarmState = alarming;
    }
}

void updateButtonStatus()
{
  // update the current millis
  currentMillis = millis();

  // Lockout the buttons if the lockout interval hasnt passed
  if (currentMillis - prevMillis >= LOCKOUT_INTERVAL)
  {
    prevMillis = currentMillis;
    LOCKOUT_FLAG = 0;
  }


  // If the button is pressed, and we havent locked it out
  if(digitalRead(BUTTON_PIN)==1 && LOCKOUT_FLAG == 0)
  {
    // Lockout further inputs 
    LOCKOUT_FLAG = 1;
    // if in a state that is considered "active", transition to disarmed and if disarmed transition to armed
    switch(alarmState){
      case disarmed: 
        alarmState = armed;
        break;
     case armed:
     case alarming:
        alarmState = disarmed;
        break;
    }
  }
}
