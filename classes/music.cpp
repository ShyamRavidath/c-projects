#include <iostream>
#include <cstring>
#include "music.h"
using namespace std;

music::music(char* t, int y, char *a, int d, char* pub) : media(t,y) {
  cout << "Music (child) constructor" << endl;
  strcpy(publisher,pub);
  strcpy(artist,a);
  duration = d;
}
int music::getDuration() {
  return duration;
}

char* music::getPublisher() {
  return publisher;
}

char* music::getArtist() {
  return artist;
}

void music::print() {
  media::print();
  cout << "Artist: " << artist << ", Duration: " << duration << ", Publisher: " << publisher << endl;
}

const char* music::getType() {
  return "music";
}
 


