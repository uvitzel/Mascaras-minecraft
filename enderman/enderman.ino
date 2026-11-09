//enderman
#include <Adafruit_NeoPixel.h>

#define LED_PIN D2
#define NUM_LEDS 71

Adafruit_NeoPixel leds(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

int brilloActual[NUM_LEDS];
int brilloObjetivo[NUM_LEDS];

unsigned long tiempoAnterior = 0;

void setup() {

  leds.begin();
  leds.setBrightness(60);
  leds.show();

  randomSeed(analogRead(A0));

  // Inicializar intensidades
  for (int i = 0; i < NUM_LEDS; i++) {
    brilloActual[i] = random(100, 200);
    brilloObjetivo[i] = random(100, 200);
  }
}

void loop() {

  if (millis() - tiempoAnterior >= 80) {

    tiempoAnterior = millis();

    for (int i = 0; i < NUM_LEDS; i++) {

      // Cambios aleatorios de intensidad
      if (random(100) < 8) {
        brilloObjetivo[i] = random(10, 256);
      }

      // Transición suave
      if (brilloActual[i] < brilloObjetivo[i]) {
        brilloActual[i] += 2;
      }
      else if (brilloActual[i] > brilloObjetivo[i]) {
        brilloActual[i] -= 2;
      }

      brilloActual[i] = constrain(brilloActual[i], 90, 255);

      int brillo = brilloActual[i];

      // Variación entre morado y violeta
      int rojo = brillo * 0.55;
      int verde = 0;
      int azul = brillo;

      // Pequeña variación aleatoria de tonalidad
      if (random(100) < 3) {
        rojo = brillo * 0.75;
      }

      leds.setPixelColor(i, leds.Color(rojo, verde, azul));
    }

    leds.show();
  }
}
