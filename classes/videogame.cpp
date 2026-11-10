#include <iostream>
#include "videogame.h"
#include <cstring>
using namespace std;

videogame::videogame(char* t, int y, char* pub, int r) : media(t,y) {
  cout << "Video (Child) Constructor" << endl;
  strcpy(publisher,pub);
  rating = r;
 
}

int videogame::getRating() {
  return rating;
}

char* videogame::getPublisher() {
  return publisher;
}
void videogame::print() {
  media::print();        
  cout << "Publisher: " << publisher << ", Rating: " << rating << endl;
}

const char* videogame::getType() {
  return "videogame";
}
  
