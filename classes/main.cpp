#include <iostream>
#include "media.h"
#include <vector>
#include "videogame.h"
using namespace std;

int main() {
  vector <media*> db;


  media *m = new videogame("Zelda", 2017, "Nintendo", 10);
  m->print();

  delete m;

  

  return 0;
}
