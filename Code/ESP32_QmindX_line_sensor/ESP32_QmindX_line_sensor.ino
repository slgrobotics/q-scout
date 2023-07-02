#include "QM_QMINDX.h"

QM_LineFollower qm_linefollower_3(3);  // Port #3
QM_RGBLed RGBLED(RGB_LED_Pin,2);
QM_Buzzer Buzzer(Buzzer_Pin);

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("IP: starting...");
}

void loop() {
  //Serial.println("... reading ...");
  int line_value = qm_linefollower_3.ReadSensors(3);
  //Serial.println(line_value);
  switch(line_value) {
    case 0:
      // both senors feel dark line
      RGBLED.setColor(1,0,255,0);
      RGBLED.setColor(2,0,255,0);
      break;
    case 1:
      // only right sensor feels dark line
      Buzzer.Tone(262, 50);
      RGBLED.setColor(1,0,255,0);
      RGBLED.setColor(2,255,0,0);
      break;
    case 2:
      // only left sensor feels dark line
      Buzzer.Tone(524, 50);
      RGBLED.setColor(1,255,0,0);
      RGBLED.setColor(2,0,255,0);
      break;
    default:
      // 3 means both sensors outside dark line
      RGBLED.setColor(1,0,0,255);
      RGBLED.setColor(2,0,0,255);
      break;
  }
  RGBLED.show();
  //delay(200);
}
