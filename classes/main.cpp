#include <iostream>
#include "media.h"
#include <vector>
#include "videogame.h"
#include <cstring>
#include <cctype>
using namespace std;

void add(vector<media*>& db);
int main() {
  vector <media*> db;


  media *m = new videogame("Zelda", 2017, "Nintendo", 10);
  m->print();
  m->getType();

  add(db);
  for (int i = 0; i < db.size(); i++) {
    db[i]->print();
  }

  

  

  return 0;
}

void add(vector<media*>& db) {
  char title[100];
  char pub[50];
  char typ[20];
  int year, rating;

  cout << "Title: ";
  cin.getline(title, 100);
  cout << "Year: ";
  cin >> year;
  cin.ignore();
  cout << "Type: ";
  cin.getline(typ,20);

  if (strcmp(tolower(typ), "videogame") == 0){
    cout << "Publisher: ";
    cin.getline(pub, 100);
    cout << "Rating: ";
    cin >> rating;
    cin.ignore();
    db.push_back(new videogame(title, year, pub, rating));
  }
}
