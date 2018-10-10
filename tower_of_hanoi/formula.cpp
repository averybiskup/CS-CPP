/*
Avery Biskup

Lab 1

Text Editor: Atom

OS: MACOS
*/

#include <iostream>
#include <string>

using namespace std;

int rPower(int n) {
  // Checking for base case
  if (n == 0)
    return 1;
  else
    // Implementing recursive aspect of this algorithm
    return 2 * rPower(n - 1); // 2 is hardcoded, and the exponent is given by main

  return 0;
}

int main() {
  cout << rPower(2) << endl;
}
