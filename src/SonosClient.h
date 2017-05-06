#include "HttpClient.h"

class SonosClient {
private:
  HttpClient http;
  char *host;
  int portnumber;
  char *roomname;
  int volume;

public:
  SonosClient(char *ip, int port, char *room, int volumelevel);
  void PlayList(String listname);
  void SetVolume(int level);
  void Talk(String text, String languagecode);
  void Playlist(String playlist);
};
