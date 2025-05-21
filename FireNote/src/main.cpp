#include <Arduino.h>

#define FLAME_SENSOR_PIN 34 //Analog
#define LED_PIN 2
#define BUZZER_PIN 12

// Gas-Schwellenwert (Kalibrieren für reale Anwendung)
const float SENSOR_MAX_PPM = 100000.0;  // Maximaler Messbereich des Sensors
const float ADC_MAX_VALUE = 4095.0;     // ESP32 ADC Auflösung (12-Bit)
float gasThreshold = 2;               // Schwellenwert in ppm

void setup() {
  Serial.begin(115200);
  pinMode(FLAME_SENSOR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

}

void alarmFunc(int input){
    if (input > gasThreshold){
      Serial.println("Feuer Alarm !!!");
      digitalWrite(LED_PIN, HIGH);
      tone(BUZZER_PIN,1000);
    }else {
      digitalWrite(LED_PIN,LOW);
      noTone(BUZZER_PIN);
    }
}

float umrechnung(float rawValue){
  float Rs = (5.0 * 10.0) / (rawValue / 4095.0) - 10.0; // Widerstand des Sensors
  float ratio = Rs / 10.0; // Verhältnis zu sauberer Luft
  float ppm;
  ppm = 1000.0 * pow(ratio, -2.95);
  return ppm;
}

void loop() {

  int rawValue = analogRead(FLAME_SENSOR_PIN);


  Serial.print("Rohwert: ");
  Serial.print(rawValue);
  Serial.print(" → ppm: ");
  Serial.println(umrechnung(rawValue));
  alarmFunc(umrechnung(rawValue));

  delay(500);
}
