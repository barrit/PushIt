#include "application.h"
#include "SonosClient.h"
#include "HttpClient.h"

SonosClient::SonosClient(char *ip, int port, char *room, int volumelevel) {
  host = ip;
  portnumber = port;
  roomname = room;
  volume = volumelevel;
}

void SonosClient::SetVolume(int volumelevel) {
  volume = volumelevel;
}

void SonosClient::Talk(String text, String languagecode) {
  http_request_t request;
  http_response_t response;
  http_header_t headers[] = {
    { "Accept" , "*/*"},
    { NULL, NULL } // NOTE: Always terminate headers will NULL
  };

  request.hostname = String(host);
  request.port = portnumber;
  request.path = String("/" + String(roomname) + "/say/"+ text.replace(" ", "%20") + "/" + languagecode + "/" + volume);
  Particle.publish("talk", request.path);
  http.get(request, response, headers);
}

void SonosClient::Playlist(String playlist) {
  http_request_t request;
  http_response_t response;
  http_header_t headers[] = {
    { "Accept" , "*/*"},
    { NULL, NULL } // NOTE: Always terminate headers will NULL
  };

  request.hostname = String(host);
  request.port = portnumber;
  request.path = String("/" + String(roomname) + "/favorite/" + playlist);
  Particle.publish("playlist", request.path);
  http.get(request, response, headers);
}
