#include <iostream>

using namespace std;
/* Three rules:
   1. No global variables
   2. No strings
   3. Include <iostream>
*/
int main(){
  int guess = 0;    // initialize user guess
  bool playing = true;    // initialize playing the game
  while (playing) {
    cout << "Welcome to Guessing Game. Enter a guess to begin" << endl;
    srand(time(NULL));
    int number = rand() % 101;    // init the number to be guessed
    int guesses = 0;    // initialize number of guess
    cin >> guess;    // take guess
    
    while (guess != number){
      guesses+=1; // add 1 guess for every guess
      if (guess > number){  // print guesses
        cout << "Too high. " << guesses << " guesses so far." << endl;
      }
      else {
       cout << "Too low. " << guesses << " guesses so far." << endl;
      }
      cin >> guess;
    }
    char play_again = 'n'; // init if user wants to play again
    cout << "You won! You took " << guesses << " guesses" << endl;
    cout << "Would you like to play again? (y/n)" << endl; // ask
    cin >> play_again;
    if (play_again == 'y'){ // if they want to play again
      playing = true; 
      srand(time(NULL)); // reset number to be guessed
      number = rand() % 101;
    }
    else{
      playing = false; // no play
    }
  }
  return 0;

}
