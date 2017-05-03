class SonosClient {

public:
  SonosClient(String ip, int port, String room, int volumelevel);
  void PlayList(String listname);
  void SetVolume(int level);
  void Talk(String text, String languagecode);
};
