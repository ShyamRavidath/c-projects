#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

struct Student {
  string studentname;
  int id;
  float gpa;
};

void add(Student* current) {
  cout << "enter id: " << endl;
  cin >> current->id;

  cout << "enter gpa: " << endl;
  cin >> current->gpa;
}  


int main(){
  vector<Student*> studentVector;

  Student *ptr = new Student;

  add(ptr);

  cout << "Add name: " << endl;
  
  cin >> ptr->studentname;
  
  add(ptr);

}  



  
