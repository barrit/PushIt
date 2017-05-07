#include "HttpClient.h"

class SonosClient {
private:
  HttpClient http;
  char *host;
  int portnumber;
  char *roomname;
  int volume;

  String favorite;
  String saywhat;
  String language = "en-us";

  void Volume(String diff);
  void Action(String room, String action, String parameter);

public:
  SonosClient(char *ip, int port, char *room, int volumelevel);
  void setFavorite(String favoritename) {favorite = favoritename;};
  void setSayWhat(String what) {saywhat = what;};
  void SetVolume(int level);
  void Talk();
  void PlayFavorite();
  void VolumeUp(short diff);
  void VolumeDown(short diff);
};
