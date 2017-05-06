#include "Flasher.h"
#include "SonosClient.h"

Flasher heartbeat(D7, 100, 1900);  //flash onboard led
SonosClient sonosclient("192.168.0.99", 5005, "office", 10);

int stereo = D0;
int button1 = D1;
int button2 = D2;

String playlist;

void setup() {
  pinMode(stereo, INPUT_PULLUP);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);

  Particle.function("setplaylist", setPlaylistName);
}

void loop() {
  if (digitalRead(stereo) == LOW) {
    // switch = on
    heartbeat.Update();
  }

  if (digitalRead(button1) == LOW) {
    sonosclient.Talk("Hello world", "en-us");
  }

  if (digitalRead(button2) == LOW) {
    sonosclient.Playlist(playlist);
  }
}

int setPlaylistName(String playlistname)
{
  playlist = playlistname;
}
