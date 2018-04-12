#include <iostream>
#include <string>
#include "NumberGuesser.h"

using namespace std;


// Defining the constructor with no parameters
NumberGuesser::NumberGuesser() {
  low = 0;
  high = 0;
  currentGuess = 0;
  originalHigh = 0;
  originalLow = 0;
}

// Defining the constructor with parameters
NumberGuesser::NumberGuesser(int lowerBound, int upperBound) {
  low = lowerBound;
  high = upperBound;
  originalLow = lowerBound;
  originalHigh = upperBound;
  currentGuess = (low + high) / 2;
}

// Function for getting the midpoint
int NumberGuesser::getMidPoint() {
  return (low + high) / 2;
}

// Function to run if the guess is below the number
void NumberGuesser::higher() {
  low = getCurrentGuess();
  currentGuess = getMidPoint();
}

// Function to run if the guess is above the number
void NumberGuesser::lower() {
  high = getCurrentGuess();
  currentGuess = getMidPoint();
}

int NumberGuesser::getCurrentGuess() {
  return currentGuess;
}

// Function for reseting the class
void NumberGuesser::reset() {
  low = originalLow;
  high = originalHigh;
  currentGuess = getMidPoint();
}
