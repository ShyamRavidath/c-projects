#include <iostream>
#include "media.h"
#include <cstring>
using namespace std;

media::media(char *t, int y) {
  cout << "Media (Parent) Constructor" << endl;
  strcpy(title,t);
  year = y;
  
}
media::~media() {
  cout << "Media destructor" << endl;
}

char* media::getTitle() {
  return title;
}

int media::getYear() {
  return year;
}

void media::print() {
  cout << title << " (" << year << ")" << endl;
}
