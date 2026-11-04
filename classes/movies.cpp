#include <iostream>
#include "movies.h"
using namespace std;

movies::movies() {
  cout << "Movies (child) Constructor" << endl;
  id = 1;
  n = 0;
}
void movies::setRating() {
  n = 1; // 1-5
}
int movies::getRating() {
  return n;
}
int child::myfunction() {
  return 200;
}
