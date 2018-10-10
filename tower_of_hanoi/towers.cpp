/*
Avery Biskup

Lab 1

Text Editor: Atom

OS: MACOS
*/

#include <iostream>
#include <string>

using namespace std;

class Tower { // Class for housing our function
  private:
    int count; // Holding count for solve function
  public:
    Tower(int n) { count = n; } // Constructor
    void solve(int, char, char, char); // Solve initialization

};

// Defining solve
// Amount of disks, first pole, second pole, third pole
void Tower::solve(int count, char source, char destination, char spare) {
  // Checking for base case
  if (count == 1)
    cout << "Move one disk from pole " << source << " to pole " << destination << endl; // Printing out instructions

  // Main recursive calls to solve the game
  // This algorithm works by using a spare pole to slowly move all of the disks on to pole B
  // Repeating this process ends up with a completed game
  else {
    solve(count - 1, source, spare, destination);
    solve(1, source, destination, spare);
    solve(count - 1, spare, destination, source);
  }
}

int main() {
  int i = 5; // Int for testing

  Tower t(i); // Object for testing
  t.solve(i, 'a', 'b', 'c'); // Running the actual function
}
