#include <iostream>
#include <vector>
#include <cstring>
#include "media.h"
#include "videogame.h"
#include "movies.h"
#include "music.h"
using namespace std;

/*
Name: Shyam Ravidath
Class: C++ programming
Program: Media database (Classes)
Instructions (case sensitive):
  Commands:  ADD, SEARCH, DELETE, QUIT
  Media types: videogame, movie, music
  Search choice: t (title) or y (year)
  Titles must be typed exactly as when added
  Confirm a delete with y (anything else cancels)
*/

// prototypes
void add(vector<media*>& db);
void search(vector<media*>& db, vector<int>& matches);
void del(vector<media*>& db);

int main() {
  vector<media*> db;   // each element points to a videogame, movies, or music object
  char cmd[20];
  bool running = true;

  while (running) {
    cout << endl << "Cmds: ADD, SEARCH, DELETE, QUIT" << endl << "> ";
    cin.getline(cmd, 20);
    if (!cin) {
      break;           // stop if input ends , error
    }
    if (strcmp(cmd, "ADD") == 0) {
      add(db);
    }
    else if (strcmp(cmd, "SEARCH") == 0) {
      vector<int> matches;    
      search(db, matches);
    }
    else if (strcmp(cmd, "DELETE") == 0) {
      del(db);
    }
    else if (strcmp(cmd, "QUIT") == 0) {
      running = false;
    }
    else {
      cout << "Unknown command." << endl;
    }
  }

  // free everything remaining in db
  for (int i = 0; i < (int)db.size(); i++) {
    delete db[i];            
  }
  db.clear();

  return 0;
}

// add; stores pointer in vector db
void add(vector<media*>& db) {
  char typ[20];
  char title[100];
  char text1[50];   // publisher (vgame/music) or dir (movie)
  char text2[50];   // artist (music)
  int year, duration, rating;

  cout << "Type (videogame, movie, music): ";
  cin.getline(typ, 20);

  bool isGame  = (strcmp(typ, "videogame") == 0); //true if inp is equal to videogame
  bool isMovie = (strcmp(typ, "movie") == 0);
  bool isMusic = (strcmp(typ, "music") == 0);

  if (!isGame && !isMovie && !isMusic) { // error handling for unknown media
    cout << "Unknown type, nothing added." << endl;
    return;
  }

  // fields every type has (these live in the parent class)
  cout << "Title: ";
  cin.getline(title, 100);
  cout << "Year: ";
  cin >> year;
  cin.ignore();              // remove leftover newline before next getline

  if (isGame) {
    cout << "Publisher: ";
    cin.getline(text1, 50);
    cout << "Rating (out of 10): ";
    cin >> rating;
    cin.ignore();
    db.push_back(new videogame(title, year, text1, rating));
  }
  else if (isMovie) {
    cout << "Director: ";
    cin.getline(text1, 50);
    cout << "Duration (minutes): ";
    cin >> duration;
    cout << "Rating (out of 10): ";
    cin >> rating;
    cin.ignore();
    db.push_back(new movies(title, year, text1, duration, rating));
  }
  else {  // music
    cout << "Artist: ";
    cin.getline(text2, 50);
    cout << "Duration (seconds): ";
    cin >> duration;
    cin.ignore();
    cout << "Publisher: ";
    cin.getline(text1, 50);
    db.push_back(new music(title, year, text2, duration, text1));
  }
  cout << "Added." << endl; //added media
}

// Search: finds items by title or year
void search(vector<media*>& db, vector<int>& matches) {
  char choice[20];
  cout << "Search by title or year? (t/y): ";
  cin.getline(choice, 20);

  if (strcmp(choice, "t") == 0) {
    char target[100];
    cout << "Title: ";
    cin.getline(target, 100);
    for (int i = 0; i < (int)db.size(); i++) {
      if (strcmp(db[i]->getTitle(), target) == 0) {   // 0 means text matches
        matches.push_back(i);
      }
    }
  }
  else if (strcmp(choice, "y") == 0) {
    int yr;
    cout << "Year: ";
    cin >> yr;
    cin.ignore();
    for (int i = 0; i < (int)db.size(); i++) {
      if (db[i]->getYear() == yr) {
        matches.push_back(i);
      }
    }
  }
  else { //eror handling
    cout << "Please type t or y." << endl;
    return;
  }

  if (matches.empty()) {
    cout << "No results found." << endl;
    return;
  }
  int count = matches.size();
  for (int k = 0; k < count; k++) {
    media* item = db[matches[k]];
    cout << "[" <<k + 1 << "] " << item->getType() << " - ";
    item->print();           
  }
}

// DELETE: uses search() to find items, asks once, then deletes them all.
void del(vector<media*>& db) {
  vector<int> matches;
  search(db, matches);
  if (matches.empty()) return;

  char answer[10];
  cout << "Delete these " << matches.size() << " item(s)? (y/n): ";
  cin.getline(answer, 10);

  if (strcmp(answer, "y") == 0) {
    // go backward
    int count = matches.size();            // how many matches there are
    for (int k = count - 1; k >= 0; k--) {
      int index = matches[k];
      delete db[index];                  // frees object (calling destructor)
      db.erase(db.begin() + index);     
    }
    cout << "Deleted the media." << endl;
  }
  else {
    cout << "Nothing deleted." << endl;
  }
}

