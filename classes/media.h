#include <iostream>
using namespace std;

#ifndef MEDIA_H
#define MEDIA_H

class media {
 public:
  media(char* t, int y);
  char* getTitle();
  int getYear();
  virtual void print();
  virtual const char* getType();
  virtual ~media();
 protected:
  char title[100];
  int year;
};



#endif
