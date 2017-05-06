#include "HttpClient.h"

class SonosClient {
private:
  HttpClient http;
  String host;
  int portnumber;
  String roomname;
  int volume;

public:
  SonosClient(String ip, int port, String room, int volumelevel);
  void PlayList(String listname);
  void SetVolume(int level);
  void Talk(String text, String languagecode);
};
