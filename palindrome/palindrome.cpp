#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main()
{
  char str[80];
  char str2[80];
  cin.get(str, 80);
  cin.get();
  int count = 0;
  int len = strlen(str);
  
  for (int i = len; i > 0; i--){
    if (ispunct(str[i-1]) == 0 && str[i-1] != ' '){ 
      if (str[i-1] != '\0'){
	cout << str[i-1] << endl;
	str2[count] = str[i-1];
	count++;
    }
    }
  }

  int ct = 0;

  // po.op
  // p = p
  // o = o
  // 
  for (int i = 0; i < len; i++){ //check if now, each char in reversed spot, is the same
    if (ispunct(str[i]) == 0 && str[i] != ' '){
      if (str2[i] == str[i]){
	ct++;
      }
    }
    
  }

  if (ct != len){ // if any one char is not the same ct != len
    cout << "Not a palindrome" << endl;
  }
  else {
    cout << "Palindrome" << endl;
  }  
  cout << len << endl; 
  
  cout << str << endl;
  cout << str2 << endl;
  return 0;
}
