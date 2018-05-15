#include <iostream>
#include "RandomNumberGuesser.h"

using namespace std;

void playOneGame(RandomNumberGuesser & r) {
  char input;
  cout << r.getCurrentGuess() << endl;
  cout << r.getCurrentGuess() << endl;
  cout << r.getCurrentGuess() << endl;

  do {
    // Getting user input
    cout << r.getCurrentGuess() << " ?\n>";
    cin >> input;

    // Parsing user input
    if (input == 'h')
      r.higher();
    else if (input == 'l')
      r.lower();
    else if (input == 'c')
      break;
    else
      continue;

  } while (input != 'c');

}

int main() {
  RandomNumberGuesser s(1, 10);
  // cout << s.getCurrentGuess() << endl;
  // cout << s.getCurrentGuess() << endl;
  // cout << s.getCurrentGuess() << endl;
  playOneGame(s);
  return 0;
}
