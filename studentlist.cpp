#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

struct Student {
  char studentname[10];
  int id;
  float gpa;
};

void add(Student *current);

int main(){
  Student mystudent;
  Student *ptr = &mystudent;

  
 
  // vector<Student> studentVector;

  // studentVector.push_back({"bob",1234,3.3});

  cin >> ptr->studentname;
  
  add(ptr);
  
  cout << mystudent.gpa << endl;

}  

void add(Student *current) {
  cout << "enter id: " << endl;
  cin >> current->id;

  cout << "enter gpa: " << endl;
  cin >> current->gpa;
}  


  
