#include <iostream>
#include "media.h"
using namespace std;

class movies : public media {
 public:
  movies();
  void setRating();
  int getRating();
  int myfunction();
 protected:
  int n;
};  
