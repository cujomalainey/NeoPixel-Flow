# NeoPixel-Flow
A short neopixel script to create a smooth color fade using an arduino.

The program uses randomly stretched and shifted sine functions to create a truly unique color fade based on your seed value. Since sine functions are continous there are no harsh jumps in the coloring unless the function is shrunk to much. This would be caused by the FREQ_MAX variable being set to high.

The adafruit neopixel library comes from https://github.com/adafruit/Adafruit_NeoPixel