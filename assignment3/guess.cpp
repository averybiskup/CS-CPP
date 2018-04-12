#include <iostream>
#include <string>
#include <time.h>

using namespace std;

// Asking user if they want to play again.
bool shouldPlayAgain() {
  cout << "Again?\n(y/n): ";
  char again;
  cin >> again;
  return (again == 'y') ? true : false;
}

// Get user input
char getUserResponseToGuess(int guess) {
  cout << "Is it: " << guess << "?\n(h/l/c): ";
  char answer;
  cin >> answer;
  return answer;
}

// Find midpoint between two ints
int getMidpoint(int first, int second) {
  return (first + second) / 2;
}

// Random number between two ints
int getRandomMidpoint(int max, int min) {
  srand(static_cast<int>(time(0)));
  return rand() % ((max - min) + 1) + min;
}

// Setting up a game
void playOneGame() {
  int max = 100;
  int min = 0;
  char input;

  cout << "Think of a number between 1 and 100" << endl;

  do {
    int ran = getRandomMidpoint(max, min);
    int norm = getMidpoint(max, min);
    char input = getUserResponseToGuess(norm); // or norm for getMidpoint

    if (input == 'h')
      min = norm; //-  For getMidpoint()
      // min = ran;

    else if (input == 'l')
      max = norm; //-  For getMidpoint()
      // max = ran;

    else if (input == 'c') {
      cout << endl;
      break;
    }

  } while (input != 'c');

}

int main() {
  do {
    playOneGame();
  } while(shouldPlayAgain());
  return 0;
}

// Midpoint
/*
Think of a number between 1 and 100
Is it: 50?
(h/l/c): l
Is it: 25?
(h/l/c): h
Is it: 37?
(h/l/c): l
Is it: 31?
(h/l/c): h
Is it: 34?
(h/l/c): c
CorrectAgain?
(y/n): n
*/

// Random midpoint
/*
Think of a number between 1 and 100
Is it: 63?
(h/l/c): l
Is it: 45?
(h/l/c): l
Is it: 17?
(h/l/c): h
Is it: 40?
(h/l/c): l
Is it: 18?
(h/l/c): c
CorrectAgain?
(y/n): y
Think of a number between 1 and 100
Is it: 9?
(h/l/c): h
Is it: 58?
(h/l/c): l
Is it: 45?
(h/l/c): l
Is it: 16?
(h/l/c): h
Is it: 23?
(h/l/c): c
CorrectAgain?
(y/n): n
*/
