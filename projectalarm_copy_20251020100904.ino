// Light-Triggered Alarm with 5s Snooze (edge-triggered)
// Wiring: Light -> A0, Button -> D4, Buzzer -> D5
// this project turns on a buzzer when there is light
// pressing the button snoozes it for 5 seconds

int lightPin  = A0;         // light sensor connected to A0
int buttonPin = 4;          // button connected to D4
int buzzerPin = 5;          // buzzer connected to D5

int lightLimit = 350;       // light level to trigger the alarm (adjust if needed)

unsigned long snoozeUntil = 0;     // time until snooze ends
unsigned long lastPressMs = 0;     // last button press time
const unsigned long snoozeMs   = 5000;  // snooze lasts 5 seconds
const unsigned long debounceMs = 120;   // delay to stop double button presses

int lastButton = HIGH;      // button starts off not pressed (HIGH with INPUT_PULLUP)

void setup() {
  pinMode(buzzerPin, OUTPUT);      // buzzer set as output
  pinMode(buttonPin, INPUT_PULLUP); // button reads HIGH until pressed
  Serial.begin(9600);              // start serial monitor for readings
}

void loop() {
  int lightValue  = analogRead(lightPin);   // read brightness from sensor
  int buttonValue = digitalRead(buttonPin); // check if button is pressed (LOW when pressed)
  unsigned long now = millis();             // get current time in milliseconds

  // check if button was just pressed (HIGH -> LOW)
  if (lastButton == HIGH && buttonValue == LOW && (now - lastPressMs) > debounceMs) {
    snoozeUntil = now + snoozeMs;           // set snooze end time (5s from now)
    lastPressMs = now;                      // remember the press time
  }
  lastButton = buttonValue;                 // update button state for next loop

  bool bright  = (lightValue > lightLimit); // check if it's bright
  bool snoozed = (now < snoozeUntil);       // check if snooze timer is still active

  // if it's bright and not snoozed, turn buzzer on
  if (bright && !snoozed) digitalWrite(buzzerPin, HIGH);
  else                    digitalWrite(buzzerPin, LOW); // otherwise buzzer off

  // print info to serial monitor (for testing)
  Serial.print("Light: "); Serial.print(lightValue);
  Serial.print("  Bright: "); Serial.print(bright);
  Serial.print("  Btn: "); Serial.print(buttonValue);
  Serial.print("  Snoozed: "); Serial.println(snoozed);

  delay(60);  // small delay to keep readings smooth
}

