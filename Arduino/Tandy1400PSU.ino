// For this board setup with a 200k/150k voltage divder I'm getting a consistent 0.0107v  per unit.
// This puts 12v right at the the very top of our range though my Arduino seems to handle that ok.


// For a 2s battery anything the maximum charge voltage is roughly 8.4v which gives us 722 as fully charged.
// The Tandy 1400 seems to cut out around 6.7~6.6 and not want to start up again, at least with the pack I'm
// using. That puts "Dead Dead" at around 6.7v.
// For mostly discharged we're somewhere around 575 which gives us a range of about 150 give or take.

#define ON_CHARGER 900

#define DEAD_BATTERY 575
#define REALLY_LOW_BATTERY 600
#define LOW_BATTERY 620
#define FULL_BATTERY 722

const int sensePin = A0;
const int chargerSensePin = A1;

// white - out
const int lowBatteryOne = 2;
// dark blue - out
const int lowBatteryTwo = 3;
// gray - out
const int powerSwitchOn = 5;
// brown - in
const int standBy = 4;
// light blue - out
const int onMains = 6;


void setup() {
  ///analogReference(DEFAULT);

  // Setup pins
  pinMode(lowBatteryOne, OUTPUT);
  pinMode(lowBatteryTwo, OUTPUT);
  pinMode(powerSwitchOn, INPUT);
  pinMode(onMains, OUTPUT);

  pinMode(standBy, INPUT);

  // This is always on, the original supply had it wired directly to the power switch.
  //digitalWrite(powerSwitchOn, HIGH);

  // Serial Console
  Serial.begin(115200);
}

void loop() {
  int newLowBatteryOne = HIGH;
  int newLowBatteryTwo = HIGH;
  int newOnMains = LOW;

  int newStandBy = digitalRead(standBy);
  int powerOn = digitalRead(powerSwitchOn);
  int sense = analogRead(sensePin);
  int chargerSense = analogRead(chargerSensePin);

  // Check if we're on mains.
  if (chargerSense > ON_CHARGER) {
    newOnMains = HIGH;

    // if we're on wall power, we don't need a low battery warning.
    newLowBatteryOne = LOW;
    newLowBatteryTwo = LOW;
  }

  // Check if we have a low battery.
  if (sense > LOW_BATTERY) {
    newLowBatteryOne = LOW;
  }

  // Check for a really low battery.
  if (sense > REALLY_LOW_BATTERY) {
    newLowBatteryTwo = LOW;
  }

  // Write Updated values.
  digitalWrite(lowBatteryOne, newLowBatteryOne);
  digitalWrite(lowBatteryTwo, newLowBatteryTwo);
  digitalWrite(onMains, newOnMains);

  if (Serial) {
    // Log Values.
    Serial.print("In Batt voltage : ");
    Serial.print(sense);
    Serial.print(" In Charge voltage : ");
    Serial.print(chargerSense);
    Serial.print(" low1: ");
    Serial.print(newLowBatteryOne);
    Serial.print(" low2: ");
    Serial.print(newLowBatteryTwo);
    Serial.print(" mains: ");
    Serial.print(newOnMains);
    Serial.print(" standBy: ");
    Serial.print(newStandBy);
    Serial.print(" powerOn: ");
    Serial.print(powerOn);
    Serial.print(" ref: ");
    Serial.print(DEFAULT);
    Serial.print(" ");
    Serial.print(INTERNAL);
    Serial.print(" ");
    Serial.print(EXTERNAL);
    Serial.print(" ");
    Serial.print("\n");
  }
  delay(400);
}
