#include <iostream>
#include <cstring>
#include "music.h"
using namespace std;

music::music() {
  cout << "Music (child) constructor" << endl;
  id = 1;
  n = 0;
  publisher[] = "None";
}
void music::setPub(char* pub[]) {
  strcpy(publisher[],pub[]);
}
void music::getPub() {
  return publisher[];
}
int music::myfunction() {
  return 200;
}
