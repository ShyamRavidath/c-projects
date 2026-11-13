#include <iostream>
#include "movies.h"
#include <cstring>
using namespace std;

movies::movies(char* t, int y, char* dir, int d, int r) : media(t,y) {
  cout << "Movies (child) Constructor" << endl;
  strcpy(director,dir);
  duration = d;
  rating = r;
}
char* movies::getDirector() {
  return director; 
}
int movies::getRating() {
  return rating;
}
int movies::getDuration() {
  return duration;
}


void movies::print() {
  media::print();
  cout << "Director: " << director << ", Duration: " << duration << ", Rating: " << rating <<\
 endl;
}

const char* movies::getType() {
  return "movies";
}

