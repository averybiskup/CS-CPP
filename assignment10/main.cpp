#include <iostream>
#include <string>
#include "NumberGuesser.h"

using namespace std;

// Getting the user response
char getUserResponse(int guess) {
  cout << "Is it: " << guess << "?\n(h/l/c): ";
  char answer;
  cin >> answer;
  return answer;
}

// Checking if the user wants to play again
bool shouldPlayAgain() {
  cout << "Again?\n(y/n): ";
  char again;
  cin >> again;
  return (again == 'y') ? true : false;
}

// Function for playing one game
void playOneGame() {
  NumberGuesser test(1, 100);

  char input;

  // Game loop
  do {
    cout << "Think of a number between 1 and 100" << endl;
    do {
      char input = getUserResponse(test.getCurrentGuess());

      // Modifying the guess based on the user input
      if (input == 'h')
        test.higher();
      else if (input == 'l')
        test.lower();
      else if (input == 'c') {
        cout << endl;
        test.reset();
        break;
      }
    } while (input != 'c');
  } while (shouldPlayAgain());

}

int main() {
  playOneGame();

  return 0;
}

// EXAMPLE

// Think of a number between 1 and 100
// Is it: 50?
// (h/l/c): h
// Is it: 75?
// (h/l/c): l
// Is it: 62?
// (h/l/c): h
// Is it: 68?
// (h/l/c): h
// Is it: 71?
// (h/l/c): h
// Is it: 73?
// (h/l/c): h
// Is it: 74?
// (h/l/c): c
//
// Again?
// (y/n): y
// Think of a number between 1 and 100
// Is it: 50?
// (h/l/c): l
// Is it: 25?
// (h/l/c): l
// Is it: 13?
// (h/l/c): h
// Is it: 19?
// (h/l/c): h
// Is it: 22?
// (h/l/c): l
// Is it: 20?
// (h/l/c): c
//
// Again?
// (y/n): n
