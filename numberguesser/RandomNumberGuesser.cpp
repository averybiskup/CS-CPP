#include <iostream>
#include "RandomNumberGuesser.h"

using namespace std;

int RandomNumberGuesser::getCurrentGuess() {
  // Making sure we don't get random nums if we don't user higher() or lower()
  if (changed == false)
    return currentGuess;
  changed = false;

  // Generating random numer and returning it if we need a new one
  int r = rand() % ((high - low) + 1) + low;
  currentGuess = r;
  return r;
}

RandomNumberGuesser::RandomNumberGuesser(int l, int h) : NumberGuesser(l, h) {
  srand(time(0)); // For random numbers
  currentGuess = 0; // setting currentGuess to 0
  changed = true; // Changed true because we need to change it at the beginning
  currentGuess = getCurrentGuess();
  low = originalLow = l;
  high = originalHigh = h;
}

void RandomNumberGuesser::higher() {
  if (high != low) {
    low = currentGuess + 1;
    changed = true; // We just changed the guess
  }
}

void RandomNumberGuesser::lower() {
  if (high != low) {
    high = currentGuess - 1;
    changed = true; // We just changed the guess
  }
}
