#include <iostream>
#include <string.h>
#include "music.h"

using namespace std;

game::game(char* newtitle, char* newpublisher, char* newyear, char* newrating){
  title = newtitle;
  publisher = newpublisher;
  year = newyear;
  rating = newrating;
}

char game::getTitle(){
  return title;
}
char game::getPublisher(){
  return publisher;
}
char game::getYear(){
  return year;
}
char game::getRating(){
  return rating;
}
