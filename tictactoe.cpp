#include <iostream>
#include <cstring>
using namespace std;

void printBoard(char board[][3]);
bool checkLegal(int row, int col, char board[][3]);
void switchPlayer(char player);
void makeMove(int row, int col, char board[][3], char player);


int main()
{
  int row = 0;
  int col = 0;
  bool playing = true;
  char player = 'x';
  char board[3][3] = {{' ',' ',' '},
		   {' ',' ',' '},
		   {' ',' ',' '}
  };
  
  while (playing) {
    cout << "Player " << player << "'s turn!" << endl;
    cout << "Enter row" << endl;
    cin >> row;
    cout << "Enter column" << endl;
    cin >> col;

    bool legal = checkLegal(row,col,board);

    if (!legal)
    {
      cout << "Not a legal move. Try again" << endl;
    }
    else
    {
      makeMove(row, col, board, player);
      printBoard(board);
      swtichPlayer(player);
    }  
  }
  return 0;
}

void printBoard(char board[][3])
{
  cout << "  " << "0" << " " << "1" << " " << "2" << endl;
  cout << "0" << " " << board[0][0] << " " << board[0][1] << " " << board[0][2] << endl;
  cout << "1" << " " << board[1][0] << " " << board[1][1] << " " << board[1][2] << endl;
  cout << "2" << " " << board[2][0] << " " << board[2][1] << " " << board[2][2] << endl;
}

bool checkLegal(int row, int col, char board[][3])
{
  //condition one: if a pos has already been played
  if (board[row][col] == 'x' || board[row][col] == 'o')
  {
    return false;
  }
  else if (row > 2 || col > 2) //condition 2: if row/col is out of range
  {
    return false;
  }
  else
  {
    return true;
  }    
  
  
}

void switchPlayer(char player)
{
  if (player == 'x')
  { 
    player = 'o';
  }
  else
  {
    player = 'x';
  }
}
void makeMove(int row, int col, char board[][3], char player)
{
  board[row][col] = player;
}  
