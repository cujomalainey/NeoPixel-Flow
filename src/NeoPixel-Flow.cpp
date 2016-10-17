#include "Adafruit_NeoPixel.h"
#include "Arduino.h"

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      256

// Define the fastest possible color change frequency
#define FREQ_MAX  400

// Change this number to get different flow patterns
// you may also change this to a variable that is randomly generated to get a pattern each run
#define RNGSEED 5

// define the maximum color brightness (between 2 and 128)
const double amplitude = 25.0;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

uint32_t spot = 0;
int w_red,p_red,w_green,p_green,w_blue,p_blue;

void setup() {
  pixels.begin(); // This initializes the NeoPixel library.
  Serial.begin(9600);
  randomSeed(RNGSEED);
  w_red = random(FREQ_MAX);
  p_red = random();
  w_green = random(FREQ_MAX);
  p_green = random();
  w_blue = random(FREQ_MAX);
  p_blue = random();
}

void loop() {
  int i;
  for(i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i,
      pixels.Color(
        (amplitude - 1)*sin((double)w_red*(double)(spot+i)/1800.0 + (double)p_red) + amplitude,
        (amplitude - 1)*sin((double)w_green*(double)(spot+i)/1800.0 + (double)p_green) + amplitude,
        (amplitude - 1)*sin((double)w_blue*(double)(spot+i)/1800.0 + (double)p_blue) + amplitude)
      );
  }
  pixels.show();
  spot++;
}
