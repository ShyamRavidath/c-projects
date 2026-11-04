#include <iostream>
#include "media.h"
using namespace std;

media::media() {
  cout << "Media (Parent) Constructor" << endl;
  id = 0;
}

int media::getid() {
  return id;
}

int media::myfunction() {
  return 100;
}
