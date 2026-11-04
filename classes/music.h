#include <iostream>
#include "media.h"
using namespace std;

class music : public media {
 public:
  music();
  void setN();
  int getN();
  int myfunction();
 protected:
  int n;
};

