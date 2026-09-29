#include <iostream>
using namespace std;

void printBoard(int board[]);
void makeMove(int col, int row, int board[]);

int main()
{
  int row = 0;
  int col = 0;
  
  cout << "Enter column" << endl;
  cin >> col;
  
  cout << "Enter row" << endl;
  cin >> row;
  
  int board[9] = {0,0,0,0,0,0,0,0,0};
  bool playing = true;

  makeMove(col, row, board);
  
  printBoard(board);
  return 0;
}

void printBoard(int board[])
{
  cout << "  " << "0" << " " << "1" << " " << "2" << endl;
  cout << "0" << " " << board[0] << " " << board[1] << " " << board[2] << endl;
  cout << "1" << " " << board[3] << " " << board[4] << " " << board[5] << endl;
  cout << "2" << " " << board[6] << " " << board[7] << " " << board[8] << endl;
}
void makeMove(int col, int row, int board[])
{
  int pos = row*3 + col;
  board[pos] = 1;
}  
