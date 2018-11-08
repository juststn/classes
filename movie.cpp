#include <iostream>
#include <string.h>
#include "movie.h"

using namespace std;

movie::movie(char* newtitle, char* newdirector, char* newyear, char* newduration, char* newrating){
  title = newtitle;
  director = newdirector;
  year = newyear;
  duration = new duration;
  rating = newrating;
}

char movie::getTitle(){
  return title;
}
char movie::getDirector(){
  return director;
}
char movie::getYear(){
  return year;
}
char movie::getDuration(){
  return duration;
}
char movie::getRating(){
  return rating;
}
