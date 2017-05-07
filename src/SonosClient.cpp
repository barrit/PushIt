#include "application.h"
#include "SonosClient.h"
#include "HttpClient.h"

SonosClient::SonosClient(char *ip, int port, char *room, int volumelevel) {
  host = ip;
  portnumber = port;
  roomname = room;
  volume = volumelevel;
}

void SonosClient::Action(String room, String action, String parameter) {
  http_request_t request;
  http_response_t response;
  http_header_t headers[] = {
    { "Accept" , "*/*"},
    { NULL, NULL } // NOTE: Always terminate headers will NULL
  };

  request.hostname = String(host);
  request.port = portnumber;
  request.path = String("/" + room + "/" + action + "/" + parameter);
  Particle.publish("sonosaction", request.path);
  http.get(request, response, headers);
}

void SonosClient::SetVolume(int volumelevel) {
  volume = volumelevel;
  Action(roomname, "volume", String(volume));
}

void SonosClient::Talk() {
  Action(roomname, "say", saywhat.replace(" ", "%20") + "/" + language + "/" + volume);
}

void SonosClient::PlayFavorite() {
  Action(roomname, "favorite", favorite.replace(" ", "%20"));
}

void SonosClient::VolumeUp(short diff) {
  volume += diff;
  Action(roomname, "volume", String("+" + String(diff)));
}

void SonosClient::VolumeDown(short diff) {
  volume -= diff;
  Action(roomname, "volume", String("-" + String(diff)));
}
