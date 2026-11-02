#include <Arduino.h>

// --- Pin Definitions ---
// Connect these ESP32 GPIOs to your L298N driver inputs
const int PIN_IN1    = 18;  // To L298N IN1 (PWM drive)
const int PIN_IN2    = 19;  // To L298N IN2 (Direction reference / LOW)
const int PIN_BUTTON = 4;   // Pushbutton on breadboard (connected between GPIO 4 and GND)
const int PIN_POT    = 34;  // Optional potentiometer wiper (ADC input)

// --- PWM Parameters ---
const int PWM_FREQ       = 5000; // 5 kHz PWM switching frequency
const int PWM_RESOLUTION = 8;    // 8-bit resolution (0 to 255)

void setup() {
    Serial.begin(115200);

    // Configure pushbutton with internal pull-up (reads LOW when pressed)
    pinMode(PIN_BUTTON, INPUT_PULLUP);

    // Configure direction reference pin
    pinMode(PIN_IN2, OUTPUT);
    digitalWrite(PIN_IN2, LOW);

    // Initialize PWM channel on PIN_IN1
    ledcAttach(PIN_IN1, PWM_FREQ, PWM_RESOLUTION);
    ledcWrite(PIN_IN1, 0);

    Serial.println("--- Laboratory 6: Actuator Control Initialized ---");
}

void loop() {
    // Button is pressed when state drops LOW
    bool isPressed = (digitalRead(PIN