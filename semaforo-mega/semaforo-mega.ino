// Semaforo para Arduino Mega 2560
// Rojo D8, amarillo D9, verde D10 (220 ohmios en cada LED).
const int rojo = 8;
const int amarillo = 9;
const int verde = 10;
void luces(bool r, bool a, bool v) {
  digitalWrite(rojo, r ? HIGH : LOW);
  digitalWrite(amarillo, a ? HIGH : LOW);
  digitalWrite(verde, v ? HIGH : LOW);
}
void setup() {
  pinMode(rojo, OUTPUT);
  pinMode(amarillo, OUTPUT);
  pinMode(verde, OUTPUT);
  luces(LOW, LOW, LOW);
}
void loop() {
  luces(HIGH, LOW, LOW);  // ROJO
  delay(5000);
  luces(LOW, HIGH, LOW);  // AMARILLO
  delay(2500);
  luces(LOW, LOW, HIGH);  // VERDE
  delay(5000);
  luces(LOW, HIGH, LOW);  // AMARILLO
  delay(2500);
}
