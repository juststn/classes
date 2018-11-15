#include <iostream>
#include <string.h>
#include "video.h"

using namespace std;

video::video(){ 
}

video::~video() {
}

void video::setPublisher(string newpublisher){
  publisher = newpublisher;
}

void video::setRating(string newrating){
  rating = newrating;
}

string video::getPublisher(){
  return publisher;
}

string video::getRating(){
  return rating;
}
