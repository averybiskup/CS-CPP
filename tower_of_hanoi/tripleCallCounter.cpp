/*
Avery Biskup

Lab 1

Text Editor: Atom

OS: MACOS
*/

#include <iostream>
#include <string>

using namespace std;


/*
  How this works:

  Algebreic Function: T(n) = 2^n - 1

  This algorithm is using this function recursively to find the answer
*/

int solveTripleCounter(int n) {
  // Checking for base cases
  if (n == 0)
    return 0;
  else if (n == 1)
    return 1;

  else
    // Implementing recursion
    return solveTripleCounter(n - 1) + solveTripleCounter(1) + solveTripleCounter(n - 1);

  return 0;
}

int main() {

  cout << solveTripleCounter(5) << endl; // Printing out function return value
  return 0;
}

// Just needs comments
