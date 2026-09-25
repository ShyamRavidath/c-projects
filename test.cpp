#include <iostream> 

using namespace std;

char input[80];

float pow(float a, int x);
float powReference(float & a, int x);
void swap(int & a, int & b);


int main (){
  float number = 3.0;
  int power = 2;
  float result = pow(number, power);
  cout << "Number is:" << number << endl;
  cout << "Answer is:" << result << endl;
  result = powReference(number, power);
  cout << "Number is:" << number << endl;
  cout << "Answer is:" << result << endl;
  return 0;
}

float pow(float a, int x){
  float answer = a;
  for (int i = 0; i < x - 1; i++){
    answer = answer * a;
  }
  a = 27.0;
  return answer;
}

float powReference(float & a, int x){
  float answer = a;
  for (int i=0; i < x-1; i++){
    answer = answer*a
  }
  a = 27.0;
  return answer;  
}

void(int & a, int & b){
  int temp = a;
  a = b;
  b = temp;
}
