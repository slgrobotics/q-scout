# Robobloq Q-Scout Robot under QmindX ESP32

### This is how to program QmindX controller under Arduino IDE 2.1.1. (Windows Store version)

This is ONLY applicable to the current 2021 version - **QmindX** - which is based on ESP32.

After installing **MyQode**, I found Arduino library code here: *C:\Program Files\MyQode\resources\remote\sources\k2x*

I packed it in a zip file, creating a library (see current folder here).

You can install this library in your *"libraries"* folder (usually found under *Sketchbook* folder), restart the IDE - and the following code should compile and run. Make sure MyQode is not connected through the same port (use "Disconnect").

Select **"ESP32 Dev Module"** as your device, and an appropriate COM port.

```
#include "QM_QMINDX.h"

QM_Buzzer Buzzer(Buzzer_Pin);

QM_DcmotorOnBoard QM_DcmotorOnBoard;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("IP: starting...");

  QM_DcmotorOnBoard.QM_DcmotorOnBoard_Init();
}

void loop() {
  Serial.println("... looping ...");
  Buzzer.Tone(262, 500);
  QM_DcmotorOnBoard.run(45,45);
  delay(2000);
  Buzzer.Tone(524, 500);
  QM_DcmotorOnBoard.run(0,0);
  delay(2000);
}
```

Now you can use **MyQode** as a reference, see how its *Scratch* blocks are translated into Arduino code, and reproduce that in a more powerful and flexible Arduino IDE - combining with anything else you like.

### Happy coding!

#### Some Observations:

1. There are four RJ45 ports on the sides of the controller. They combine I2C and ADC (analog input) wires. Four more ports are present, but connectors aren't soldered. See Docs folder, Photos.md for details.
2. Port numbers are marked on the plastic case. Port 1 is next to Reset button, port 4 is near USB connector.
3. Due to very low pin count of ESP32, hardware designers had to use analog multiplexor chips - CM051B - to handle all ports. This complicates direct programming. You have to use library calls, or handle multiplexor yourself.
4. When switching/connecting back to MyQode, you will see a message "Unofficial Firmware". Click "Factory Reset", and your Scratch programs will upload and work fine.

