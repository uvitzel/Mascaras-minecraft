//calabaza
#include <Adafruit_NeoPixel.h>

#define LED_PIN D2
#define NUM_LEDS 71

Adafruit_NeoPixel leds(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  leds.begin();
  leds.setBrightness(100);
  leds.show();

  randomSeed(analogRead(A0));
}

void loop() {

  for (int i = 0; i < NUM_LEDS; i++) {

    // Intensidad aleatoria
    int flicker = random(100, 256);

    // Variación de intensidad
    int red = flicker;
    int green = map(flicker, 100, 255, 15, 105);
    int blue = 0;

    // Destellos amarillos ocasionales
    if (random(100) < 8) {
      green = random(100, 150);
    }

    // Aplicar color
    leds.setPixelColor(i, leds.Color(red, green, blue));
  }

  leds.show();

  // Velocidad del fuego
  delay(random(200, 240));
}
