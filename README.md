Light-Triggered Alarm with 5s Snooze
Project Overview

This project is a small IoT system made with the Arduino UNO R4 WiFi and the Arduino Sensor Kit.
It works like a smart alarm — when the light sensor detects brightness, the buzzer turns on.
Pressing the button snoozes the alarm for 5 seconds before it starts again.

How It Works

The light sensor (A0) reads how bright the room is.

If the reading goes above 350, it counts as bright and the buzzer turns on.

The button (D4) can be pressed to stop the buzzer for 5 seconds (snooze).

After 5 seconds, the buzzer will start again if the light is still bright.

Hardware Setup
Component	Pin on Arduino	Description
Light Sensor	A0	Detects brightness
Button	D4	Used to snooze alarm
Buzzer	D5	Makes sound when bright


Code

The main code file is:
projectalarm_copy_20251020100904.ino
It contains the full working code with comments explaining each line.

Testing

When the light is covered → buzzer stays off.

When the light is bright → buzzer turns on.

When button is pressed → buzzer stops for 5 seconds.

Works fully as planned and tested using the Serial Monitor.
