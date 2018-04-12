#include <iostream>
#include <string>

using namespace std;

// Initializing the class
class NumberGuesser {

  // Private functions and variables
  private:
    int low;
    int high;
    int currentGuess;
    int getMidPoint();
    int originalLow;
    int originalHigh;

  // Public functions
  public:
    NumberGuesser();
    NumberGuesser(int lowerBound, int upperBound);
    void higher();
    void lower();
    int getCurrentGuess();
    void reset();
};
