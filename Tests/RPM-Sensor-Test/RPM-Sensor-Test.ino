const    byte interruptPin =  2;
const    byte ledPin       = 13;
volatile long counter      =  0;

         long lastOutput   =  0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin,       OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blip, FALLING);
  Serial.begin(115200);
  lastOutput = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13, digitalRead(2));

  if (millis() - lastOutput > 100) {
    Serial.println(counter);
    lastOutput += 100;
  } 
}

void blip() {
  counter++;
}

