#include "Flasher.h"
#include "SonosClient.h"

Flasher heartbeat(D7, 100, 1900);  //flash onboard led
SonosClient sonosclient("192.168.0.99", 5005, "office", 10);

int stereo = D0;
int button = D1;

void setup() {
  pinMode(stereo, INPUT_PULLUP);
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(stereo) == LOW) {
    // switch = on
    heartbeat.Update();
  }

  if (digitalRead(button) == LOW) {
    sonosclient.Talk("Hello world", "en-us");
  }

}
