#include <iostream>
#include "media.h"
#include <vector>
#include "videogame.h"
#include "movies.h"
#include "music.h"
#include <cstring>
#include <cctype>
using namespace std;
/*
Name: Shyam Ravidath
Date: Nov 13th
Class: C++ programming
*/

//prototypes
void add(vector<media*>& db);
void search(vector<media*>& db);
void del(vector<media*>& db);

int main() {
  vector <media*> db;
  media *v = new videogame("Zelda", 2017, "Nintendo", 10);
  db.push_back(v);

  media *m = new movies("inception", 2017, "nolan", 102, 9);
  db.push_back(m);

  media *mu = new music("element", 2017, "popsmoke", 100, "billboard");
  db.push_back(mu);
  
  for (int i = 0; i < db.size(); i++) {
    db[i]->print();
  }


  return 0;

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
  if (strcmp(typ, "videogame") == 0){
    cout << "Publisher: ";
    cin.getline(pub, 100);
    cout << "Rating: ";
    cin >> rating;
    cin.ignore();
    db.push_back(new videogame(title, year, pub, rating));
  }
  else {
    cout << "Unknown type, nothing added." << endl;
  }
  
}

void search(vector<media*>& db) { // search by year
  int yr;
  cout << "Enter year: " << endl;
  cin >> yr;
  cin.ignore();
  for (media* ptr : db) {
    int obj = ptr->getYear();
    if (obj == yr) {
      ptr->print();
    }
    else {
      cout << "No results for that year" << endl;
    }
  }

}

void del(vector<media*>& db) { // search by year and del
  int yr;
  char delo[2];

  int i = 0;


  cout << "Enter year: " << endl;
  cin >> yr;
  cin.ignore();
  for (media* ptr : db) {
    int obj = ptr->getYear();
    if (obj == yr) {
      cout << "Are you sure you want to delete this media? (y/n)" << endl;
      cin >> delo;
      cin.ignore();
      if (strcmp(delo,"y") == 0) {
	delete ptr;
	db.erase(db.begin() + i);
      }
      else {
	continue;
      }
      }
    else {
      cout << "No results for that year" << endl;
    }

    i++;
  }

}

