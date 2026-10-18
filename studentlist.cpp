#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

/*
  Name: Shyam Ravidath
  Assignment: Studentlist
  Date: 10/16/26
*/


// student info
struct Student {
  char first[50];
  char last[50];
  int id;
  float gpa;
};


void add(vector<Student*>& list) {
  
  Student* s = new Student;
  cout << "First name: ";
  cin >> s->first;
  cout << "Last name: ";
  cin >> s->last;
  cout << "ID: " << endl;
  cin >> s->id;
  cout << "GPA: " << endl;
  cin >> s->gpa;

  list.push_back(s); //add new student
}  

void print(vector<Student*>& list) {
  for (vector<Student*>::iterator it = list.begin(); it != list.end(); ++it) {

    // turn Gpa into whole cents
    int cents = (int)((*it)->gpa * 100 + 0.5);
    
    cout << (*it)->first << " " << (*it)->last << ", " << (*it)->id << ", ";
    
    cout << cents / 100 << "."; // dec point
    if (cents % 100 < 10) {
      cout << "0"; // pad, need to diff .05 from 0.5
    }  
    cout << cents % 100 << endl;
  }
}



void del(vector<Student*>& list) {
  int id;
  cout << "ID to delete: ";
  cin >> id;
  
  for (vector<Student*>::iterator it = list.begin(); it != list.end(); ++it) {
    if ((*it)->id == id) {
      delete *it;        // remove struct
      list.erase(it);    // remove pointer from vector
      return;            // stop
    }
  }
  cout << "No student with that id" << endl;
}


  
int main(){
  vector<Student*> list;
  char command[20];

  while (true) {
    cout << "Say command ADD,PRINT,DELETE,QUIT: ";
    cin >> command;

    if (strcmp(command, "ADD") == 0) {
      add(list);
    } else if (strcmp(command, "PRINT") == 0) {
      print(list);
    } else if (strcmp(command, "DELETE") == 0) {
      del(list);
    } else if (strcmp(command, "QUIT") == 0) {
      break;
    }
  }

  //now to free any left over students:

  for (vector<Student*>:: iterator it = list.begin(); it != list.end(); ++it) {
    delete *it;
  }  

}  



  
