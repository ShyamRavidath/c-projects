#include <iostream>
#include "media.h"
#include <vector>
#include "videogame.h"
#include <cstring>
using namespace std;

int main() {
  vector <media*> db;


  media *m = new videogame("Zelda", 2017, "Nintendo", 10);
  m->print();
  m->getType();

  add(vector<media*>& db);
  cout << db;

  delete m;

  

  return 0;
}

void add(vector<media*>& db) {
  char title[100];
  char pub[50];
  char type[20];
  int year, rating;

  cout << "Title: ";
  cin.getline(title, 100);
  cout << "Year: ";
  cin >> year;
  cout << "Type: ";
  cin.getline(type,20);
  if (strcmp(type,"videogame")){
    cout << "Publisher: ";
    cin.getline(title, 100);
    cout << "Rating: ";
    cin >> rating;
    db.push_back(new videogame(title, year, pub, rating));
  }
}
