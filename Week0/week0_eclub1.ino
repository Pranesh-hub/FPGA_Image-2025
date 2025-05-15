int current_led = 1;
unsigned long previousMillis = 0;

void setup() {
  for (int pin = 3; pin <= 10; pin++) {
    pinMode(pin, OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  int pot1 = analogRead(A0);
  int pot2 = analogRead(A1)'
  
  int buzzerPin = map(pot1, 0, 675, 8, 10);
  int speedfactor = map(pot2, 0, 675, 100, 1000);
  
  Serial.print(pot1);
  Serial.print(" ");
  Serial.print(pot2);
  Serial.print(" ");
  Serial.print(buzzerPin);
  Serial.print(" ");
  Serial.println(speedfactor);
  
  for (int i = 8; i <= 10; i++) {
    digitalWrite(i, (i == buzzerPin) ? HIGH : LOW);
  }

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= speedfactor) {
    previousMillis = currentMillis;

    for (int i = 3; i <= 7; i++) {
      digitalWrite(i, LOW);
    }

    digitalWrite(current_led + 2, HIGH);

    current_led++;
    if (current_led > 5) current_led = 1;
  }
}
