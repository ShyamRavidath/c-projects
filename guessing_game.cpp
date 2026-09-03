#include <iostream>

using namespace std;
/* Three rules:
   1. No global variables
   2. No strings
   3. Include <iostream>
*/
int main(){
  int guess = 0;
  bool playing = true;
  while (playing) {
    srand(time(NULL));
    int number = rand() % 101;

    cin >> guess;
    while (guess != number){
      if (guess > number){
        cout << "Too high: " << guess << endl;
      }
      else {
        cout << "Too low: " << guess << endl;
      }
      cin >> guess;
    }
    cout << "You won! Would you like to play again? (y/n)" << endl;
    bool playing = false;
  }

}
