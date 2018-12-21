/* File:  Queens.h */

#ifndef QUEENS_H
#define QUEENS_H

#include <iostream>

using std::cout;

/** @class Queens
 * The Queen class. */
class Queens
{
 private:
  // chess board -- a C++ 2-dimensional dynamic array
  int **board;

  // squares per row or per column
  const static int BOARD_SIZE = 8;

  //used to indicate empty square
  const static int EMPTY = 0;

  //used to indicate square contains a queen
  const static int QUEEN = 1;

 public:
  Queens();
  // --------------------------------------------------
  //  Constructor:  Create an empty square board.
  // --------------------------------------------------

  void clearBoard();
  // --------------------------------------------------
  // Clears the board.
  // Precondition:  None.
  // Postcondition:  Sets all squares to EMPTY
  // --------------------------------------------------

  void displayBoard();
  // --------------------------------------------------
  // Displays the board.
  // Precondition:  None.
  // Postcondition:  Board is written to standartd
  // output; zero is an EMPTY square, one is a square
  // containing a queen (QUEEN)
  // --------------------------------------------------

  bool placeQueens(int column);
    // --------------------------------------------------
    // Place queens in columns of the board beginning
    // at the column specified.
    // Precondition:  Queens are placed correctly in
    // columns 1 thro coulumn-1.
    // Postcondition:  If a solution is found, each
    // column of the board contains one queen and method
    // returns true; otherwise retruns false (no
    // solution existis for a queen anywhere in column
    // specified).
    // --------------------------------------------------

  void setQueen(int row, int column);
    // --------------------------------------------------
    // Set a queen at square indicated by row and
    // column.
    // Precondition:  None.
    // Postcondition:  Sets the square on the board in a
    // given row and column to QUEEN.
    // --------------------------------------------------

  void removeQueen(int row, int column);
    // --------------------------------------------------
    // Remove a queen at square indicated by row and
    // column.
    // Precondition:  None.
    // Postcondition:  Sets the square on the board in a
    // given row and column to EMPTY.
    // --------------------------------------------------

  bool isUnderAttack(int row, int column);
    // --------------------------------------------------
    // Determines whether the square on the board at a
    // given row and column is under attack by any queens
    // in the columns 1 through column-1.
    // Precondition:  Each column between 1 and column-1
    // has a queen placed in a square at a specific row.
    // None of these queens can be attacked by any other
    // queen.
    // Postcondition:  If the deignated square is under
    // attack, returns true; otherwise, returns false.
    // --------------------------------------------------


}; // end Queens

#endif
