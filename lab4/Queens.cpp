/* File:  Queens.cpp */

#include "Queens.h"
#include <iostream>

using namespace std;

Queens::Queens() {
    int rows = BOARD_SIZE;
    int columns = BOARD_SIZE;

    // memory allocated for elements of rows.
    board = new int *[rows] ;

    // memory allocated for elements of each column.
    for( int i = 0 ; i < rows ; i++ )
      board[i] = new int[columns];

} // end constructor

void Queens::clearBoard() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = EMPTY;
    }
  }
   // place your logic to implement this method here
}  // end clearBoard

void Queens::displayBoard() {
  for (int i=0; i<BOARD_SIZE; i++) {
    for (int j=0; j<BOARD_SIZE; j++) {
      if (board[i][j] == QUEEN) {
        cout << QUEEN << " ";
      } else {
        cout << EMPTY << " ";
      }
      // cout << " 0 ";
      // place your logic to implement this method here
      // that prints a single row of the chess board
      // to the console window (i.e., standard output)
    }
    std::cout << "\n";
    // this newline prints after a row
    // of the chess board has been printed
  }
}  // end displayBoard

bool Queens::placeQueens(int column) {
  if (column > BOARD_SIZE) {
    return true;  // base case
  }
  else {
    bool queenPlaced = false;
    int row = 1;  // number of square in column

    while ( !queenPlaced && (row <= BOARD_SIZE)  )  {
      // if square can be attacked
      if (isUnderAttack(row, column)) {
	++row;  // consider next square in column
      } // end if
      else {  // place queen and consider next column
	setQueen(row, column);
	queenPlaced = placeQueens(column+1);
	// if no queen is possible in the next column,
	if (!queenPlaced) {
	  // backtrack:  remove queen placed earliers
	  // and try next square in column
	  removeQueen(row, column);
	  ++row;
	} // end if
      } // end if
    } // end while
    return queenPlaced;
  } // end if
} // end placeQueens

void Queens::setQueen(int row, int column) {
  board[row-1][column-1] = QUEEN;
} // end setQueen

void Queens::removeQueen(int row, int column) {
  board[row-1][column-1] = EMPTY;
} // end setQueen

bool Queens::isUnderAttack(int row, int column) {
  // check column
  for (int i=0; i<row-1; i++){
    if (board[i][column-1]==1){
      return true;
    }
  }
  // check row
  for (int i=0; i<column-1; i++) {
    if (board[row-1][i] == 1){
      return true;
    }
  }

  // check lower diagnal
  int lower_dir_row = row-2;
  int lower_dir_column = column-2;
  while (lower_dir_row>=0 && lower_dir_column>=0){
    if (board[lower_dir_row][lower_dir_column]==1){
      return true;
    } else {
      lower_dir_row = lower_dir_row -1;
      lower_dir_column = lower_dir_column -1;
    }
  }

  // check upper diagnal
  int upper_dir_row = row;
  int upper_dir_column = column-2;
  while (upper_dir_row<BOARD_SIZE && upper_dir_column>=0){
    if(board[upper_dir_row][upper_dir_column] ==1){
      return true;
    }else{
      upper_dir_row = upper_dir_row +1;
      upper_dir_column = upper_dir_column -1;
    }
  }
  return false;

} // end isUnderAttack
