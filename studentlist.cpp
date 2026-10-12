#include <iostream>
#include <cstring

using namespace std;

struct S {
  //char fname[10];
  //char lname[10];
  //int id;
  //float gpa;

  int a = 5;
  int b = 7;
};


int main(){
  Student myStruct;
  S* ptrStruct;
  ptrStruct = new S();
  byValueS(myStruct);
  byValueS(*ptrStruct);
  byRefS(myStruct);
  byRefS(*ptrStruct);

  S* originalStruct = &myStruct;
  byPtrValS(originalStruct);
  byPtrRefS(ptrStruct);
  cout << "Terminated" << endl;
}

void byValueS(S newS) {
  newS.a = 10;
  newS.b = 15;
}

void byRefS(S &newS) {
  newS.a = 20;
  newS.b = 25;
}

void byPtrValS(S* newPtr) {
  newPtr->a = 30;
  newPtr->b = 35;
  newPtr = new S();
  newPtr->a = 40;
  newPtr->b = 45;
}

void byPtrRefS(S* &newPtr) {
  newPtr->a = 50;
  newPtr->b = 55;
  newPtr = new S();
  newPtr->a = 60;
  newPtr->b = 60;
}


  
