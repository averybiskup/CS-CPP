// Assignment 1: Avery Biskup
// This program prints out as many asterisks as the user wants.

#include <iostream>

using namespace std;

int main() {

  int count;
  char goAgain = 'y';

  while (goAgain != 'n') {
    cout << "How many asterisks?: ";
    cin >> count;

    for (int i = 0; i < count; i++) {
      cout << "*";
    }

    cout << endl;
    cout << "Go again? (y/n): ";
    cin >> goAgain;
  }
  return 0;
}

/* SAMPLE OUTPUT

[rwicke@hills ~]$ ./a.out

How many asterisks?: 3

***

Go again? (y/n): y

How many asterisks?: 10

**********

Go again? (y/n): y

How many asterisks?: 1

*

Go again? (y/n): n

[rwicke@hills ~]$

*/
