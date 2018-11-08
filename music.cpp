#include <iostream>
#include <string.h>
#include "music.h"

using namespace std;

music::music(char* newtitle, char* newartist, char* newyear, char* newduration, char* newpublisher){
  title = newtitle;
  artist = newartist;
  year = newyear;
  duration = new duration;
  publisher = newpublisher;
}

char music::getTitle(){
  return title;
}
char music::getArtist(){
  return artist;
}
char music::getYear(){
  return year;
}
char music::getDuration(){
  return duration;
}
char music::getPublisher(){
  return publisher;
}
