#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

// Black Jack

using namespace std;

// Getting a random number between 1 and 10:
int getRandom() {
  int num = 1 + rand() % 10;
  return num;
}

int main() {

  // For the random number
  srand(static_cast<int>(time(0)));

  string want, again;

  int total;
  int dealerTotal;

  // Main Game Loop
  do {
    int firstRandom = getRandom(), secondRandom = getRandom(), dealerCard = getRandom();

    // dealers score
    dealerTotal += dealerCard;

    cout << "Dealer starts with a " << dealerCard << endl;
    cout << "First Cards: " << firstRandom << ", " << secondRandom << endl;

    total = 0;
    total += firstRandom + secondRandom;

    cout << "Total: " << total << endl;

    // Loop for getting more cards
    do {
      int newDealerCard = getRandom();

      cout << "Another card?\n(y/n): ";
      cin >> want;

      // if they want another card:
      if (want == "y") {
        cout << "Dealer gets a "<< newDealerCard << endl;
        dealerTotal += newDealerCard;

        int newNum = getRandom();
        total += newNum;
        cout << "Number: " << newNum << " | Total: " << total << endl;
      }

    } while (want == "y" && total < 22);

    // Calculating results
    string result;
    if (total > 21)
      result = "BUST - Dealer Wins";

    else if (dealerTotal == total)
      result = "PUSH";

    else if (dealerTotal > total && dealerTotal <= 21)
      result = "Dealer Wins: - Score: " + to_string(dealerTotal);

    else
      result = "Win! - Final Score: " + to_string(total);

    cout << "-----{ " + result + " }-----" << endl;

    cout << "\nPlay again?\n(y/n): ";
    cin >> again;

  } while (again == "y");

  return 0;
}

// EXAMPLE

/*
First Cards: 8, 3
Total: 11
Another card?
(y/n): y
Number: 10 | Total: 21
Another card?
(y/n): n
-----{ Final Score: 21 }-----

Play again?
(y/n): y
First Cards: 3, 4
Total: 7
Another card?
(y/n): y
Number: 5 | Total: 12
Another card?
(y/n): y
Number: 2 | Total: 14
Another card?
(y/n): y
Number: 5 | Total: 19
Another card?
(y/n): n
-----{ Final Score: 19 }-----

Play again?
(y/n): y
First Cards: 10, 3
Total: 13
Another card?
(y/n): y
Number: 4 | Total: 17
Another card?
(y/n): y
Number: 6 | Total: 23
-----{ BUST }-----

Play again?
(y/n): n

*/


// EXAMPLE WITH DEALER

/*
Dealer starts with a 9
First Cards: 8, 10
Total: 18
Another card?
(y/n): y
Dealer gets a 10
Number: 6 | Total: 24
-----{ BUST - Dealer Wins }-----

Play again?
(y/n): y
Dealer starts with a 8
First Cards: 1, 5
Total: 6
Another card?
(y/n): y
Dealer gets a 2
Number: 7 | Total: 13
Another card?
(y/n): n
-----{ Win! - Final Score: 13 }-----

Play again?
(y/n): y
Dealer starts with a 4
First Cards: 1, 9
Total: 10
Another card?
(y/n): y
Dealer gets a 6
Number: 1 | Total: 11
Another card?
(y/n): n
-----{ Win! - Final Score: 11 }-----

Play again?
(y/n): n
*/
