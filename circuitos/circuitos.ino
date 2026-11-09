// Semaforo de tres luces - Arduino Mega 2560
// Conexiones: D8 rojo, D9 amarillo, D10 verde.
// Cada LED lleva una resistencia de 220 ohmios en serie y catodo a GND.
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
  encender(true, false, false);   // Alto
  delay(5000);
  encender(false, false, true);   // Siga
  delay(5000);
  encender(false, true, false);   // Precaucion
  delay(2000);
}
