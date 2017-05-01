#include "HttpClient.h"
#include "Flasher.h"

Flasher heartbeat(D7, 100, 1900);  //flash onboard led

int stereo = D0;
int button = D1;

HttpClient http;

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
    SonosTalk("Hello world", "en-us", 20);
  }

}

void SonosTalk(String what, String language, int volume) {

  http_header_t headers[] = {
    { "Accept" , "*/*"},
    { NULL, NULL } // NOTE: Always terminate headers will NULL
  };

  http_request_t request;
  http_response_t response;

  request.hostname = "192.168.0.99";
  request.port = 5005;
  request.path = String("/office/say/"+ what.replace(" ", "%20") + "/" + language + "/" + volume);
  http.get(request, response, headers);
}
