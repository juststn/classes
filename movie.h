#include <iostream>
#include <string.h>
#include "media.h"

//class for movie

using namespace std;

class movie : public Media {
  public:
  movie();
  ~movie();
  
  string getDirector();
  string getDuration();
  string getRating();

  void setDirector(string);
  void setDuration(string);
  void setRating(string);
  
private:
  string director;
  string duration;
  string rating;

};
