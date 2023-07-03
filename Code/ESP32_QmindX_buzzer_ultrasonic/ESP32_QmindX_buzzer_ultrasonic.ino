#include "QM_QMINDX.h"

// Library: https://github.com/slgrobotics/q-scout/blob/main/Code/RoboBloq.zip
// Use Arduino IDE 2.1.1. (Windows Store version). Select "ESP32 Dev Module" as your device.

QM_Ultrasonic ul_2(2);  // Port #2
QM_Buzzer Buzzer(Buzzer_Pin);

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("IP: starting...");
}

void loop() {
  Serial.println("... reading ...");
  double distance = ul_2.Uldistance(2); // centimeters
  Serial.println(distance);
  if(distance < 20) {
    Buzzer.Tone(262, 100);
  }
  delay(200);
}
