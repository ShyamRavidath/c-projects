#include <iostream>
#include "media.h"
using namespace std;

#ifndef MOVIES_H
#define MOVIES_H
class movies : public media {
 public:
  movies(char *t, int y,  char* dir, int d, int r);
  int getDuration();
  int getRating();
  char* getDirector();
  void print();
  const char* getType();
 protected:
  char director[50];
  int rating;
  int duration;
};  

#endif
