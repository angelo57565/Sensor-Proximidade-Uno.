/*
=====================================================
 Projeto: Sensor de Proximidade com LED e Buzzer
 Placa: Arduino Uno
 Sensor: HC-SR04
 Autor: Angelo Shimizu
=====================================================
*/

const int trigPin = 9;
const int echoPin = 10;
const int ledPin = 7;
const int buzzerPin = 6;

long duracao;
int distancia;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);
  Serial.println("Sistema iniciado...");
}

void loop() {

  // Gera pulso ultrassônico
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Lê o tempo do eco
  duracao = pulseIn(echoPin, HIGH);

  // Converte para distância (cm)
  distancia = duracao * 0.034 / 2;

  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  // Lógica do alerta
  if (distancia > 20) {
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
  }
  else if (distancia > 10) {
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 1000);
    delay(300);
    noTone(buzzerPin);
    delay(300);
  }
  else {
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 2000);
  }

  delay(100);
}