// Prueba mínima para el flujo Duo → GitHub Actions → Mokxi.
// Sustituye este sketch al importar o crear el circuito real en Mokxi.
constexpr int ledPin = LED_BUILTIN;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
  Serial.println("Ready");
}

void loop() {
  digitalWrite(ledPin, !digitalRead(ledPin));
  delay(250);
}

