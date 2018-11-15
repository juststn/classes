#include <iostream>
#include <string>
#include "media.h"

//class for music

using namespace std;

class music : public Media {
  public:
  music();
  ~music();
  
  string getArtist();
  string getDuration();
  string getPublisher();

  void setArtist(string);
  void setDuration(string);
  void setPublisher(string);
		    
private:
  string artist;
  string duration;
  string publisher;
  
};
