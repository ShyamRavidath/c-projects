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
    int guesses = 0;
    cin >> guess;
    while (guess != number){
      guesses+=1;
      if (guess > number){
        cout << "Too high. " << guesses << " guesses so far." << endl;
      }
      else {
       cout << "Too low. " << guesses << "guesses so far." << endl;
      }
      cin >> guess;
    }
    char play_again = 'n';
    cout << "You won! Would you like to play again? (y/n)" << endl;
   
    cin >> play_again;
    if (play_again == 'y'){
        playing = true;
        srand(time(NULL));
        number = rand() % 101;
    }
    else{
    playing = false;
    }
  }
  return 0;

}
