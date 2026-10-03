#include <iostream>
#include <cstring>
using namespace std;
/*
  Name: Shyam Ravidath
  Assignment: TicTacToe
  Date: 10/2/26
*/


// init all functions

void printBoard(char board[][3]);
bool checkLegal(int row, int col, char board[][3]);
bool checkWin(char player, char board[][3]);
bool checkTie(char board[][3]);

void switchPlayer(char player); // debug/legacy
void makeMove(int row, int col, char board[][3], char player);



int main()
{
  char rowLetter; //letter, later will be used to convert to array column
  int row = 0;
  int col = 0;
  bool playing = true;
  char player = 'x';
  char board[3][3] = {{' ',' ',' '},
		   {' ',' ',' '},
		   {' ',' ',' '}
  };

  int xWins = 0;
  int oWins = 0;
  char again = 'y';
  
  while (again == 'y')
  {
    for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        board[i][j] = ' ';
      }
    }

    player = 'x';
    playing = true;
    printBoard(board);
    while (playing)
    {
      cout << "Player " << player << "'s turn!" << endl;
      cout << "Enter row (a-c)" << endl;
      cin >> rowLetter;
      cout << "Enter column (1-3)" << endl;
      cin >> col;

      if (rowLetter == 'a')
	{
	  row = 0;
	}
      else if (rowLetter == 'b')
	{
	  row = 1;
	}
      else if (rowLetter == 'c')
	{
	  row = 2;
	}
      else
	{
	  row = -1;   // invalid letter, checkLegal reject
	}

      col = col - 1;   // user types 1-3 (-1 = array)

      bool legal = checkLegal(row,col,board);

      if (!legal)
	{
	  cout << "Not a legal move. Try again" << endl;
	}
      else
	{
	  makeMove(row, col, board, player);
	  printBoard(board);
	  bool win = checkWin(player,board);
	  bool tie = checkTie(board);
	  
	  // win or tie
	  if (win)
	    {
	      cout << "Player " << player << " wins!" << endl;
	      if (player == 'x')
	      {
		xWins++;
	      }
	      else
	      {
		oWins++;
	      }
	      playing = false;
	    }
	  else if (tie)
	    {
	      cout << "This game was a tie" << endl;
	      playing = false;
	    }
	  
	  //player switch
	  if (player == 'x')
	    {
	      player = 'o';
	    }
	  else
	    {
	      player = 'x';
	    }
	} // end of legal
      
    } // end of playing

    cout << "X wins: " << xWins << " O wins: " << oWins << endl;
    cout << "Play again (y/n)" << endl;
    cin >> again;
  } // end of again
}// end main

void printBoard(char board[][3])
{
  cout << " 1 2 3" << endl;
  cout << "a" << " " << board[0][0] << " " << board[0][1] << " " << board[0][2] << endl;
  cout << "b" << " " << board[1][0] << " " << board[1][1] << " " << board[1][2] << endl;
  cout << "c" << " " << board[2][0] << " " << board[2][1] << " " << board[2][2] << endl;
}

bool checkLegal(int row, int col, char board[][3])
{
  //condition one: range
  if (row < 0 || row  > 2 || col < 0 || col > 2)
  {
    return false;
  }
  else if (board[row][col] == 'x' || board[row][col] == 'o') //condition two: filled
  {
    return false;
  }
  else
  {
    return true;
  }    
  
  
}

bool checkTie(char board[][3]) // check if all filled
{
  int count = 0;
  for (int i = 0; i<3; i++)
  {
    for (int j = 0; j<3; j++)
    {
      if (board[i][j] == ' ')
      {
	count++;
      }
    }
  }

  if (count == 0)
  {
    return true;
  }
  else
  {
    return false;
  }  
}
bool checkWin(char player, char board[][3]) // win
{
  //condition 1: diagonal win

  if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
  {
    return true;
  }
  else if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
  {
    return true;
  }

  // condition 2: row win
  int count = 0; 
  for (int i = 0; i<3; i++)
  {
    count = 0;
    for (int j = 0; j<3; j++)
    {
      if (board[i][j] == player)
      {
	count++;
      }
    }
    if (count == 3)
    {
      return true;
    }
  }

  int ct = 0;
  for (int i = 0; i<3; i++)
  {
    ct = 0;
    for (int j = 0; j<3; j++)
    {
      if (board[j][i] == player)
      {
        ct++;
      }
    }
    if (ct == 3)
    {
      return true;
    }
  }

  return false;


  
}   

void makeMove(int row, int col, char board[][3], char player) //place player on board
{
  board[row][col] = player;
}  
