#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

// student info
struct Student {
  char first[50];
  char last[5];
  int id;
  float gpa;
};

void add(vector<Student*>& list) {
  
  Student* s = new Student;
  cout << "First name: ";
  cin >> s->first;
  cout << "Last name: ";
  cin >> s->last;
  cout << "ID:  " << endl;
  cin >> s->id;
  cout << "GPA:  " << endl;
  cin >> s->gpa;

  list.push_back(s); //add new student
}  

void print(vector<Student*>& list) { // THIS WORKS!! - need to try iterator next
  for (int i = 0; i < (int)list.size(); i++) {
    Student* currentStudent = list[i];


    //current pointer extraction
    char* firstName = currentStudent->first; 
    char* lastName  = currentStudent->last;
    int studentId   = currentStudent->id;
    float studentGpa = currentStudent->gpa;


    //rounding math
    float multiplied = studentGpa * 100.0f;
    float rounded = multiplied + 0.5f;
    int totalCents = (int)rounded;

    int wholePart = totalCents / 100;
    int decimalPart = totalCents % 100;

    // student info output
    cout << firstName << " " << lastName << ", " << studentId << ", ";


    // two digit formatting for gpa
    cout << wholePart << ".";
    if (decimalPart < 10) {
      cout << "0"; // leading 0 for nums
    }

    cout << decimalPart;
    
    cout << endl;
  }
  
}


void del(vector<Student*>& list) { // iterator attempt
  int id;
  cout << "Student ID to delete: ";
  cin >> id;
  
  cout << "No student with that ID." << endl;
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



  
