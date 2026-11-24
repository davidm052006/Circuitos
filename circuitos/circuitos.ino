// Semaforo Arduino Mega 2560 con pulsador de avance.
const byte leds[] = {10, 11, 12, 11};
const unsigned long duracion[] = {5000, 2000, 5000, 2000};
const byte BOTON = 2;
const unsigned long ACELERADO = 500;
byte fase = 0;
unsigned long inicio, limite, cambioBoton;
bool lectura = HIGH, estable = HIGH;

void iniciarFase(unsigned long ahora) {
  for (byte pin = 10; pin <= 12; pin++) digitalWrite(pin, LOW);
  digitalWrite(leds[fase], HIGH);
  inicio = ahora;
  limite = duracion[fase];
}

void setup() {
  for (byte pin = 10; pin <= 12; pin++) pinMode(pin, OUTPUT);
  pinMode(BOTON, INPUT_PULLUP);
  cambioBoton = millis();
  iniciarFase(millis());
}

void loop() {
  unsigned long ahora = millis();
  bool actual = digitalRead(BOTON);
  if (actual != lectura) {
    lectura = actual;
    cambioBoton = ahora;
  }
  if (lectura != estable && ahora - cambioBoton >= 30) {
    estable = lectura;
    if (estable == LOW) {
      unsigned long transcurrido = ahora - inicio;
      if (transcurrido < limite && limite - transcurrido > ACELERADO)
        limite = transcurrido + ACELERADO;
    }
  }
  if (ahora - inicio >= limite) {
    fase = (fase + 1) % 4;
    iniciarFase(ahora);
  }
}
