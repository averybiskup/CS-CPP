#include <iostream>
#include <string>

using namespace std;

const int mainLen = 8, insideLen = 5;

// Testing if there is a number in our lengths array
bool multiple(int hand[], int len, int num) {
  for (int i = 0; i < len; i++) {
    if (hand[i] >= num) {
      return true;
    }
  }
  return false;
}

bool containsPair(int hand[], int len) {
  return (multiple(hand, len, 2));
}

bool containsTwoPair(int hand[], int len) {
  int total = 0;
  // Making sure we have two pairs
  for (int i = 0; i < len; i++) {
    if (hand[i] >= 4)
      total += 2;
    else if (hand[i] >= 2)
      total += 1;
  }
  return (total >= 2);
}

bool containsThreeOfaKind(int hand[], int len) {
  return (multiple(hand, len, 3));
}

bool containsStraight(int hand[], int len) {
  int total = 0;
  // Making sure that we have five arrays with 1 element in a row
  for (int i = 0; i < len; i++) {
    if (hand[i] == 1)
      total += 1;
    else
      total = 0;
    if (total == 5)
      break;
  }
  return (total == 5);
}


bool containsFullHouse(int hand[], int len) {
  int total = 0;
  for (int i = 1; i < len; i++) {
    if (hand[i] == 3)
      total += 1;
    else if (hand[i] == 2)
      total += 1;
  }
  return (total >= 2);
}

bool containsFourOfaKind(int hand[], int len) {
  return (multiple(hand, len, 4));
}

int getLen(int arr[], int len) {
  int total = 0;
  for (int i = 0; i < len; i++) {
    if (arr[i] != 0)
      total += 1;
  }
  return total;
}

string checkHand(int lengths[], int len) {
  if (containsFourOfaKind(lengths, len))
    return "Four of a kind!";
  else if (containsFullHouse(lengths, len))
    return "Full House!";
  else if (containsStraight(lengths, len))
    return "Straight!";
  else if (containsThreeOfaKind(lengths, len))
    return "Three of a kind!";
  else if (containsTwoPair(lengths, len))
    return "Two Pair!";
  else if (containsPair(lengths, len))
    return "One Pair!";
  else {
    return "High!";
  }
}

void construct(int arr[], const int len) {
  // Main arr holding each inputted values
  // This stores the amount of each number in it's respective index of the overall array
  // Example: [3, 0, 0, 0, 2, 0, 0, 0] - 3 1's and 2 5's
  int mainArr[mainLen][insideLen] = {{0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}};

  // Adding values to main arr
  for (int i = 0; i < len; i++) {
    // We have to make sure we are adding each number at the correct index in their own arrays
    // So we get the length of that current arr and then add to that index
    mainArr[arr[i] - 2][getLen(mainArr[arr[i] - 2], 5)] = arr[i];
  }

  // An arr of the length of the array with each number and it's correct index
  // Example: Say if there are 3 5's and 2 7's, we would have [0, 0, 0, 3, 0, 2, 0, 0]
  int lengths[mainLen] = {0};

  // Adding number's lengths to arr
  for (int n = 0; n < mainLen; n++) {
    lengths[n] = getLen(mainArr[n], insideLen);
  }

  cout << checkHand(lengths, mainLen) << endl;
}

// Main game start up
void runGame() {
  int numArr[insideLen] = {0};

  cout << "Enter five numeric cards, no face cards. Use 2 - 9.\n" << endl;

  // Getting card inputs
  for (int i = 0; i < insideLen; i++) {
    cout << "Card " << i + 1 << ": ";
    int num;
    cin >> num;

    // Fool proofing card input
    if (num >= 2 && num <= 9) {
      numArr[i] = num;
    } else {
      cout << "Oops, invalid number" << endl;
      i -= 1;
    }
  }

  construct(numArr, insideLen);
}

int main() {
  runGame();
  return 0;
}

// Example

/*
Enter five numeric cards, no face cards. Use 2 - 9.

Card 1: 2
Card 2: 5
Card 3: 5
Card 4: 5
Card 5: 5
Four of a kind!

Enter five numeric cards, no face cards. Use 2 - 9.

Card 1: 5
Card 2: 7
Card 3: 5
Card 4: 7
Card 5: 7
Full House!

Enter five numeric cards, no face cards. Use 2 - 9.

Card 1: 3
Card 2: 4
Card 3: 5
Card 4: 6
Card 5: 7
Straight!

Enter five numeric cards, no face cards. Use 2 - 9.

Card 1: 5
Card 2: 5
Card 3: 3
Card 4: 5
Card 5: 7
Three of a kind!

*/
