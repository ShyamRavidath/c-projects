#include <iostream>
using namespace std;
#include "media.h"
#ifndef VIDEOGAME_H
#define VIDEOGAME_H

class videogame : public media {
 public:
  videogame(char *t, int y, char *pub, int r);
  int getRating();
  char* getPublisher();
  void print();
 protected:
  char publisher[50];
  int rating;
  
};
#endif


