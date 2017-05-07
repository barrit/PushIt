#include "HttpClient.h"

class SonosClient {
private:
  HttpClient http;
  char *host;
  int portnumber;
  char *roomname;
  int volume;
  void Volume(String diff);
  void Action(String room, String action, String parameter);

public:
  SonosClient(char *ip, int port, char *room, int volumelevel);
  void Favorite(String favorite);
  void SetVolume(int level);
  void Talk(String text, String languagecode);
  void PlayFavorite(String favorite);
  void VolumeUp(short diff);
  void VolumeDown(short diff);
};
