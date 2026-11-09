// Semaforo Arduino Mega 2560
// D8 rojo, D9 amarillo, D10 verde.
// Usar una resistencia de 220 ohmios por LED y catodos a GND.
const byte LED_ROJO = 8;
const byte LED_AMARILLO = 9;
const byte LED_VERDE = 10;

void encender(bool rojo, bool amarillo, bool verde) {
  digitalWrite(LED_ROJO, rojo ? HIGH : LOW);
  digitalWrite(LED_AMARILLO, amarillo ? HIGH : LOW);
  digitalWrite(LED_VERDE, verde ? HIGH : LOW);
}

void setup() {
  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_AMARILLO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  encender(false, false, false);
}

void loop() {
  encender(true, false, false);   // Rojo
  delay(5000);
  encender(false, true, false);   // Amarillo antes de verde
  delay(2000);
  encender(false, false, true);   // Verde
  delay(5000);
  encender(false, true, false);   // Amarillo antes de rojo
  delay(2000);
}
