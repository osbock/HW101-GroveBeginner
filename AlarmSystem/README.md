# Alarm System

A basic alarm system that can be armed, disarmed, and turned off when the alarm goes off

## Setup

- Plug the Motion Sensor into D2

- Plug the RGB strip into D3

## Use

To enable the alarm, disable or disarm, press the button (D6). 

When armed, the RGB strip will be Green.

When disarmed, the RGB strip will be off.

When alarming, the RGB strip will be Red and the buzzer will buzz.

## Adding more features

To build on this project, you can add more behavior in the `switch` statement in `loop()` for arm, disarm, and alarming.

Things you can add:
- Show the current state on the OLED
- Flash the LED strip RED when the alarm is going off
- Set the state to `alarming` when the Sound sensor (A2) detects a loud noise
- Use the Rotary Potentiometer (A0) as a dial for entering passwords

## Things to know

- Using the enum for state management allows us to handle the three different states of the alarm using a switch statement.
- An interrupt can be called at any time. We should've declared `alarmState` as `volitile` but in this specific case, we likely won't run into major issues
- The button should be using an interrupt as well. However, the Arduino Uno that the Grove Beginner Kit uses has the interrupt hooked to D3 not D6 like the button needs. As such, we use `millis()` to function as a simple lockout function to help debounce the button.
- The buzzer uses two tones, one after the other, to reset the tone function. Using `noTone` is another option
