# Robobloq Q-Scout Robot under QmindX ESP32

### This is how to program QmindX controller under Arduino IDE 2.1.1. (Windows Store version)

This is ONLY applicable to the current 2021 version - **QmindX** - which is based on ESP32.

After installing **MyQode**, I found Arduino library code here: *C:\Program Files\MyQode\resources\remote\sources\k2x*

I packed it in a zip file, creating a library (see current folder here, file **RoboBloq.zip**).

You can install (copy) this library into your *"libraries"* folder (usually found under the *Sketchbook* folder, check File->Preferences):

<img width="533" alt="Screenshot 2023-07-02 170636" src="https://github.com/slgrobotics/q-scout/assets/16037285/810ba41d-34a1-4bb0-8881-ae2fe8c8e895">

<img width="532" alt="Screenshot 2023-07-02 170713" src="https://github.com/slgrobotics/q-scout/assets/16037285/822a83df-3899-4e5b-9799-7af9779efb4e">

Now you can restart Arduino IDE - and the following code should compile and run. Make sure MyQode is not connected through the same port (use "Disconnect").

Select **"ESP32 Dev Module"** as your device, and an appropriate COM port (mine shows as "USB-SERIAL CH340 COM3").

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

1. There are four RJ45 ports on the sides of the controller (see [Photos](https://github.com/slgrobotics/q-scout/blob/main/Docs/Photos.md)). They combine I2C and ADC (analog input) wires. Four more ports are present, but connectors aren't soldered. See Docs folder, Photos.md for details.
2. Port numbers are marked on the plastic case. Port 1 is next to Reset button, port 4 is near USB connector.
3. Motor numbers are also marked on plastic, M1 is Left, M2 is Right.
4. Only the motors require battery power, sensors are happy with USB supplied +5V 500 mA. Keep power switch off to save the battery.
5. Due to very low pin count of ESP32, hardware designers had to use analog multiplexor chips - CM051B - to handle all ports. This complicates direct programming. You have to use library calls, or handle multiplexor yourself.
6. When switching/connecting back to MyQode, you will see a message "Unofficial Firmware". Click "Factory Reset", and your Scratch programs will upload and work fine. Click "Disconnect" before running Arduino IDE.
7. Even on an Intel I7 Windows 10 PC, compiling and uploading is slow, both in MyQode and Arduino IDE. This is an ESP32 "feature".
8. MyQode doesn't allow you to copy and paste Arduino or Python code. Ask why at hello@robobloq.com
9. Expect random hanging of your PC ("blue screen"). Save your work. Exit MyQode and run it again often. Software quality, you know... One more reason to use Arduino IDE.
10. I haven't attempted Python programming - it would require re-flashing ESP32 and other tricks. Welcome to try - and tell the world.

#### Note: I am not Support and might not respond to your questions. Feel free to fork this repository and create Pull Requests, if you want to suggest improvements. I MIGHT take a look.


