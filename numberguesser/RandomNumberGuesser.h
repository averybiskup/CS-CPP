
#ifndef RANDOMNUMBERGUESSER_H
#define RANDOMNUMBERGUESSER_H

#include <iostream>
#include "NumberGuesser.h"

class RandomNumberGuesser: public NumberGuesser {
  private:
    int currentGuess; // The current guess
    bool changed; // Keeps track of changes made to currentGuess

  public:
    RandomNumberGuesser(); // Default Constructor
    RandomNumberGuesser(int l, int h); // Constructor with parameters
    int getCurrentGuess(); // In order to get the current guess
    void higher(); // Overwritten higher function
    void lower(); // Overwritten lower function
};

#endif
