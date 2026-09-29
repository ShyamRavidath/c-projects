#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main()
{
  //read up2 80 chars
  char str[81];
  char str2[81];
  cin.get(str, 81);
  cin.get();
  int count = 0;
  int len = strlen(str);

  for (int i = len; i > 0; i--){ //skip punc, spaces, lowercasing along the way (results in reveresed)
    if (ispunct(str[i-1]) == 0 && str[i-1] != ' '){ 
      if (str[i-1] != '\0'){
	// debug: cout << str[i-1] << endl;
	str2[count] = tolower(str[i-1]);
	count++;
    }
    }
  }
  str2[count] = '\0'; // null terminate str2
  int ct = 0;

  for (int i = 0; i < count / 2; i++){ // compare str2 against itself
      if (str2[i] == str2[count - 1 - i]){
	ct++;
      }
    
  }

  if (ct != count / 2){ // mirror pair match (half = half)
    cout << "Not a palindrome" << endl;
  }
  else {
    cout << "Palindrome" << endl;
  }  
  /* debug:
  cout << len << endl; 
  cout << str << endl;
  cout << str2 << endl;
  */
  return 0;
  
}
