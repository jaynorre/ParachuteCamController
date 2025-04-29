# ParachuteCamController
An Arduino project for controlling a parachute camera using a button, distance sensor, buzzer, LED, and servo motor to capture pictures during descent. Created during my high school senior year engineering class.

# Overview
This project is designed to automatically take a picture during a parachute drop.
The system uses a button to start a countdown, then monitors the distance sensor.
When the object comes close enough, it triggers the servo to press the camera button.
When the picture has been taken, the LED and buzzer will activate.

# Features
Button to start a 5 second countdown.
Buzzer beeps once every second during the countdown.
Distance sensor monitors how close the ground is.
Servo motor presses the camera button when distance is reached.
LED lights up when a picture has been taken.

# Components Used
Arduino Uno,
HC-SR04 Ultrasonic Distance Sensor,
Red LED + 330 ohm resistor,
Active Buzzer,
Servo Motor,
Push button (I used 2 prong but 4 prong will work),
9V High Performance Battery,
Capacitor (I used 470μF for power smoothing),
Breadboard and jumper wires

# Wiring
Distance Sensor Trig = D10,
Distance Sensor Echo = D9,
LED = D11,
Buzzer = D13,
Servo Motor Signal = D6,
Button = D2

Note:
Servo VCC connects to 5v.
Distance VCC connects to 5v.
Connect Capacitor across 5v and ground rails.

# How It Works
Press the button to start a 5 second countdown (The buzzer will beep each second).
After countdown, the distance sensor will become active.
When the distance sensor detects an object within the set distance, it will activate the buzzer and LED, move the servo to press the camera button, and keep the LED on to show that a picture was taken.
System resets on every button push.

# Power Recommendation
Make sure batteries are sufficient to power the system. If you are using 9V batteries, I recommend at least 600 mAh to make sure the system will run smoothly.

# License
This project is licensed under the MIT License,

# Author
Jamir (Jay) Grady-Riley <br/>
Senior year engineering class project
