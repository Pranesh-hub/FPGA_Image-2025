int current_led = 1;
unsigned long previousMillis = 0;//this is necessadry because i want to delay only the led action the buzzer should be able to change its state instantly

void setup() {
  for (int pin = 3; pin <= 10; pin++) {
    pinMode(pin, OUTPUT);
  }//easy way to setup :)
  // Serial.begin(9600);
}

void loop() {
  int pot1 = analogRead(A0);//take analog input from potentiometer 1
  int pot2 = analogRead(A1);//take analog input from potentiometer 2
  
  int buzzerPin = map(pot1, 0, 675, 8, 10);//finding buzzerpin using map
  int speedfactor = map(pot2, 0, 675, 100, 1000);//delay factor
  
  // Serial.print(pot1);
  // Serial.print(" ");
  // Serial.print(pot2);
  // Serial.print(" ");
  // Serial.print(buzzerPin);
  // Serial.print(" ");
  // Serial.println(speedfactor);
  
  for (int i = 8; i <= 10; i++) {
    digitalWrite(i, (i == buzzerPin) ? HIGH : LOW);//set only the required buzzer high and rest low
  }

  unsigned long currentMillis = millis();//from here the use this function helps for independant control of led from buzzer
  if (currentMillis - previousMillis >= speedfactor) {
    previousMillis = currentMillis;

    for (int i = 3; i <= 7; i++) {
      digitalWrite(i, LOW);//set all led low
    }

    digitalWrite(current_led + 2, HIGH);//set current led high

    current_led++;
    if (current_led > 5) current_led = 1;//if reached last led then go to 1st led again
  }
}
//https://www.tinkercad.com/things/bBWNzDVDAqy-epic-albar/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard&sharecode=RkPVxw04eCCMxqfU9WYq6o2yRgEY-k-h52P1DlwI-L8
