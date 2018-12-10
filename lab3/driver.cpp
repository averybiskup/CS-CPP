#include <iostream>
#include <string>
#include <ctime>

#include "LinkedList.cpp"
#include "Node.cpp"

using namespace std;

// Function for printing out a list
void print(LinkedList<int> a, int len) {
  cout << "List: " << endl;
  for (int i = 1; i <= len; i++) {
    cout << a.getEntry(i) << " ";
  }
  cout << "\n<---------->\n" << endl;
}

// Function for getting and creating a linked list
LinkedList<int> getInput() {
  // Original list
  LinkedList<int> a;

  cout << "Enter list of ints: ";
  string input;
  getline(cin, input);
  // cin.ignore(1000, 10);

  // Getting input, and putting it into a list
  int p = 0;
  for (int i = 0; i < input.length(); i++) {
    string num;
    if (!isspace(input[i])) {
      for (int n = i; n < input.length(); n++) {
        if (isspace(input[n]))
          break;
        num += input[n];
        i++;
      }
    }
    if (num.length())
      p++;
      a.insert(p, atoi(num.c_str()));
  }

  return a;
}

int main() {
  // Input vars
  int swap;
  int to;
  string another;

  // Input loop
  do {
    // Input item to swap
    LinkedList<int> a = getInput();

    cout << "Swap: ";
    cin >> swap;
    // if (!swap) return 0;

    // Input item to swap int to
    cout << "To: ";
    cin >> to;
    // if (!to) return 0;

    // Swapping the item
    int swaps = a.replaceItem(swap, to);

    cout << "New ";
    print(a, a.getLength());
    cout << swaps << " swaps" << endl;

    cout << "Another? (y/n)" << endl;
    getline(cin, another);
    cin >> another;
    cin.ignore(1000, 10);

  } while (another == "y");
  return 0;
}
