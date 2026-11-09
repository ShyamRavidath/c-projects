#include <iostream>
#include <vector>
#include "child.h"
using namespace std;


int main() {

  child* c = new child;
  vector<parent*> storage;
  storage.push_back(c);

  
  return 0;
}
