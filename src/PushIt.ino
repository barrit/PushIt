#include "Flasher.h"
#include "SonosClient.h"

Flasher heartbeat(D7, 100, 1900);  //flash onboard led
SonosClient sonosclient("192.168.0.99", 5005, "office", 10);

int stereo = D0;
int button1 = D1;
int button2 = D2;
int volup = D3;
int voldown = D4;

void setup() {
  pinMode(stereo, INPUT_PULLUP);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(volup, INPUT_PULLUP);
  pinMode(voldown, INPUT_PULLUP);

  Particle.function("setfavorite", setFavoriteName);
  Particle.function("saywhat", setSayWhat);
}

void loop() {
  if (digitalRead(stereo) == LOW) {
    // switch = on
    heartbeat.Update();
  }

  if (digitalRead(button1) == LOW) {
    sonosclient.Talk();
  }

  if (digitalRead(button2) == LOW) {
    sonosclient.PlayFavorite();
  }

  if (digitalRead(volup) == LOW) {
    sonosclient.VolumeUp(2);
  }

  if (digitalRead(voldown) == LOW) {
    sonosclient.VolumeDown(2);
  }
}

int setFavoriteName(String favorite)
{
  sonosclient.setFavorite(favorite);
  return 1;
}

int setSayWhat(String what)
{
  sonosclient.setSayWhat(what);
  return 1;
}
