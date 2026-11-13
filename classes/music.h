#include <iostream>
#include "media.h"
using namespace std;

class music : public media {
 public:
  music(char *t, int y, char *a, int d, char* pub);
  int getDuration();
  char* getPublisher();
  char* getArtist();
  void print();
  const char* getType();
  
 protected:
  int duration;
  char publisher[100];
  char artist[100];
  
};

