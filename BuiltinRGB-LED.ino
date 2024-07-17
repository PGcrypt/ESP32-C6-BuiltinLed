#define LED_PIN     39    // Pin for Neopixel LEDs
#define NUM_LEDS    1     // Number of connected LEDs

// List of colors (Red, Green, Blue)
const uint8_t colors[][3] = {
  {255, 0, 0},    // Red
  {0, 255, 0},    // Green
  {0, 0, 255}     // Blue
};

int bldel = 50; // Blink delay in milliseconds

const int numColors = sizeof(colors) / sizeof(colors[0]);

void setup() {
  // Initialize Neopixel pin
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // Color transition between all colors
  for (int i = 0; i < numColors; i++) {
    int nextColor = (i + 1) % numColors; // Next color in the list
    
    // Transition from colors[i] to colors[nextColor]
    blendColors(colors[i], colors[nextColor]);
  }
  
  // Blink each color sequentially
  for (int i = 0; i < 5; i++) {
    blinkRed();
    blinkGreen();
    blinkBlue();
  }
}

////////////////   Functions   ///////////////////////////////////////////////////

void blendColors(const uint8_t color1[3], const uint8_t color2[3]) {
  uint8_t r1 = color1[0];
  uint8_t g1 = color1[1];
  uint8_t b1 = color1[2];
  uint8_t r2 = color2[0];
  uint8_t g2 = color2[1];
  uint8_t b2 = color2[2];
  
  // Number of steps for the transition
  int steps = 100;
  
  // Color transition
  for (int step = 0; step <= steps; step++) {
    uint8_t r = map(step, 0, steps, r1, r2);
    uint8_t g = map(step, 0, steps, g1, g2);
    uint8_t b = map(step, 0, steps, b1, b2);
    
    // Set the color of the Neopixel LEDs
    neopixelWrite(LED_PIN, r, g, b);
    
    // Short delay for smooth transition
    delay(10);
  }
}

// Functions for blinking individual LEDs

void blinkRed() {
  neopixelWrite(LED_PIN, 255, 0, 0);  // Red
  delay(bldel);
  neopixelWrite(LED_PIN, 0, 0, 0);    // Off
  delay(bldel);
}

void blinkGreen() {
  neopixelWrite(LED_PIN, 0, 255, 0);  // Green
  delay(bldel);
  neopixelWrite(LED_PIN, 0, 0, 0);    // Off
  delay(bldel);
}

void blinkBlue() {
  neopixelWrite(LED_PIN, 0, 0, 255);  // Blue
  delay(bldel);
  neopixelWrite(LED_PIN, 0, 0, 0);    // Off
  delay(bldel);
}
