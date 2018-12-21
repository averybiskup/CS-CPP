#include <iostream>
#include "Queens.h"

using namespace std;

int main () {
  Queens a;
  a.setQueen(5, 1);
  a.displayBoard();

  cout << "Solution: \n" << endl;
  a.placeQueens(2);
  a.displayBoard();

  cout << "Cleared: \n" << endl;
  a.clearBoard();
  a.displayBoard();


  return 0;
}
