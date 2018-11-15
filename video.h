#include <iostream>
#include <string.h>
#include "media.h"

//class for video

using namespace std;

class video : public Media {
  public:
  video();
  ~video();
  
  string getPublisher();
  string getRating();

  void setPublisher(string);
  void setRating(string);
  
private:
  string publisher;
  string rating;

};
