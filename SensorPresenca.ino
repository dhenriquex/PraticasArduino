const int trigPin = 5;
const int echoPin = 4;
const int ledPin = 2;
const int buzzerPin = 3;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  long duration, distance;
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distancia: ");
  Serial.println(distance);

  if (distance > 0 && distance < 30) { // Altere a distância conforme necessário
    digitalWrite(ledPin, HIGH); // Acende o LED
    tone(buzzerPin, 1000); // Ativa o buzzer com um som de 1000 Hz
  } else {
    digitalWrite(ledPin, LOW); // Desliga o LED
    noTone(buzzerPin); // Desativa o buzzer
  }

  delay(100);
}
