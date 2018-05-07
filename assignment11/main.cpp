#include <iostream>
#include <string>
#include "IntCollection.h"

using namespace std;

int main() {
  IntCollection c;

  c.add(45);
  c.add(-210);
  c.add(77);
  c.add(2);
  c.add(-21);
  c.add(42);
  c.add(7);

  c.printOut();

  IntCollection a;
  IntCollection b(c);

  b.printOut();

  a = b = c;

  a << 25 << 5;

  a.printOut();

  cout << "Same: " << (a == b) << endl;
  cout << "Same: " << (b == c) << endl;



  return 0;
}


// QUESTION 6
// error: 'addCapacity' is a private member of 'IntCollection'
// Since it is private, when I try to call it my compiler just gives me an error


// SAMPLE
// ==========
// 45
// -210
// 77
// 2
// -21
// 42
// 7
// ==========
//
// ==========
// 45
// -210
// 77
// 2
// -21
// 42
// 7
// 25
// 5
// ==========
//
// Same: 0
// Same: 1
