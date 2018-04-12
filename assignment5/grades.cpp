#include <iostream>
#include <string>

using namespace std;

// Swaps two elements in an array of ints
void swapInt(int & num1, int & num2) {
  int temp = num1;
  num1 = num2;
  num2 = temp;
}

// Swaps two elements in an array of strings
void swapString(string & num1, string & num2) {
  string temp = num1;
  num1 = num2;
  num2 = temp;
}

// for copying arrays into another array
void copyArrStr(string arr1[], string arr2[], int len) { for (int i = 0; i < len; i++) { arr2[i] = arr1[i]; } }
void copyArrInt(int arr1[], int arr2[], int len) { for (int i = 0; i < len; i++) { arr2[i] = arr1[i]; } }

// For printing out an array of ints to the screen
void printArrInt(int * arr, int len) {
  cout << "[";
  for (int i = 0; i < len; i++) {
    if (i < 4) cout << *(arr + i) << ", ";
    else cout << *(arr + i);
  }
  cout << "]" << endl;
}

// For printing out an array of strings onto the screen
void printArrString(string * arr, int len) {
  cout << "[";
  for (int i = 0; i < len; i++) {
    if (i < 4) cout << *(arr + i) << ", ";
    else cout << *(arr + i);
  }
  cout << "]" << endl;
}

// Displaying data from the sorting algorithms
void displayData(string * names, int * grades, int size, string type) {
    cout << type << endl;
    for (int i = 0; i < size; i++) {
      cout << *(names + i) << " | " << *(grades + i) << endl;
    }
    printArrInt(grades, size);
    printArrString(names, size);
    cout << "\n" << endl;
}


// Sorting arrays using bubble sort
int sortDataBubble(string * names, int * grades, int size, string sortBy) {
  // Deciding what to print out to the screen, (sorting array of strings, or ints)
  (sortBy == "grade") ? printArrInt(grades, size) : printArrString(names, size);

  int iterations = 0, total = 0;

  do {
    total = 0;
    for (int i = 0; i < size - 1; i++) {
      int firstNum, secondNum;
      string firstString, secondString;

      // This bit is for testing if we want to sort an array of strings or array of ints
      if (sortBy == "grade") {
        // This is for if we are sorting an array of ints
        firstNum = *(grades + (i + 1)), secondNum = *(grades + i);
      } else {

        // This is for if we are sorting an array of strings, so we want to test the first letter value of each string in the array
        string firstString = *(names + i), secondString = *(names + (i + 1));
        firstNum = int(toupper(firstString[0])), secondNum = int(toupper(secondString[0])); // The brackets are just for getting first char of String not accessing array
      }

      // Swapping elements in the array if they need to be.
      if (firstNum > secondNum) {
        swapInt(*(grades + i), *(grades + (i + 1)));
        swapString(*(names + i), *(names + (i + 1)));
        total += 1;
        iterations += 1;
      }
    }
  } while (total != 0);

  displayData(names, grades, size, "Bubble sort by " + sortBy + ":");
  return iterations;
}

// Sorting arrays with selection sort
int sortDataSelection(string * names, int * grades, int size, string sortBy) {
  // Deciding what to print out to the screen, (sorting array of strings, or ints)
  (sortBy == "grade") ? printArrInt(grades, size) : printArrString(names, size);

  int min, iterations = 0;

  for (int i = 0; i < size - 1; i++) {
    min = i;

    for (int j = i + 1; j < size; j++) {
      // We do this to decide if we want to sort the array based on the first letter of each element, or the int value
      if (sortBy == "name") {
        // For array of strings
        string firstString = *(names + j), secondString = *(names + min);
        if (int(toupper(firstString[0])) < int(toupper(secondString[0]))) // The brackets are just for getting first char of String not accessing array
          min = j;
      }
      else {
        // For array of ints
        if (*(grades + j) > *(grades + min))
          min = j;
      }
    }

    // Swapping two elements in the array if neccesary.
    if (i != min) {
      swapInt(*(grades + min), *(grades + i));
      swapString(*(names + min), *(names + i));
      iterations += 1;
    }
  }

  displayData(names, grades, size, "Selection sort by " + sortBy + ":");
  return iterations;
}

// Initializing the arrays that we will use
void initializeArrays(string * names, int * grades, int size) {
  cout << "Enter students names and grades from (0 - 100)" << endl;

  // Getting users' input
  for (int i = 0; i < size; i++) {
    cout << "Name-" << i << ": ";
    string name = "";
    cin >> name;
    cout << "Grade-" << i << ": ";
    int grade = 0;
    cin >> grade;
    *(names + i) = name;
    *(grades + i) = grade;
  }
  cout << "\n" << endl;
}

// Printing out the results of the sorting algorithms
// Where the parameters are the iterations of each algorithm
void printIterations(int stringSwapsBubble, int bubbleSwaps, int stringSwapsSelection, int selectionSwaps) {
  cout << "Bubble Sort Swaps: " << endl;
  cout << "Names: " << stringSwapsBubble << endl;
  cout << "Grades: " << bubbleSwaps << "\n" << endl;

  cout << "Selection Sort Swaps: " << endl;
  cout << "Names: " << stringSwapsSelection << endl;
  cout << "Grades: " << selectionSwaps << endl;
}


int main() {
  const int LENGTH = 5;

  // Our 2 arrays
  string names[LENGTH] = {""};
  int grades[LENGTH] = {0};

  // Giving them the users' values
  initializeArrays(names, grades, LENGTH);

  // Printing out the results of the sorting algorithms
  int grades2[5] = {0};
  string names2[5] = {};

  // Making sure we are using the same unsorted arr each time we pass it in to be sorted
  copyArrStr(names, names2, 5);
  copyArrInt(grades, grades2, 5);

  int sortDataBubbleName = sortDataBubble(names2, grades2, LENGTH, "name");
  int sortDataBubbleGrade = sortDataBubble(names2, grades2, LENGTH, "grade");

  // Making sure we are using the same unsorted arr each time we pass it in to be sorted
  copyArrStr(names, names2, 5);
  copyArrInt(grades, grades2, 5);

  int sortDataSelectionName = sortDataSelection(names2, grades2, LENGTH, "name");
  int sortDataSelectionGrade = sortDataSelection(names2, grades2, LENGTH, "grade");

  printIterations(sortDataBubbleName, sortDataBubbleGrade, sortDataSelectionName, sortDataSelectionGrade);


  return 0;
}

// Examples

/*
Enter students names and grades from (0 - 100)
Name-0: Zavier
Grade-0: 96
Name-1: Ben
Grade-1: 40
Name-2: Samuel
Grade-2: 67
Name-3: Avery
Grade-3: 100
Name-4: Brian
Grade-4: 73


[Zavier, Ben, Samuel, Avery, Brian]
Bubble sort by name:
Avery | 100
Ben | 40
Brian | 73
Samuel | 67
Zavier | 96
[100, 40, 73, 67, 96]
[Avery, Ben, Brian, Samuel, Zavier]


[100, 40, 73, 67, 96]
Bubble sort by grade:
Avery | 100
Zavier | 96
Brian | 73
Samuel | 67
Ben | 40
[100, 96, 73, 67, 40]
[Avery, Zavier, Brian, Samuel, Ben]


[Zavier, Ben, Samuel, Avery, Brian]
Selection sort by name:
Avery | 100
Ben | 40
Brian | 73
Samuel | 67
Zavier | 96
[100, 40, 73, 67, 96]
[Avery, Ben, Brian, Samuel, Zavier]


[100, 40, 73, 67, 96]
Selection sort by grade:
Avery | 100
Zavier | 96
Brian | 73
Samuel | 67
Ben | 40
[100, 96, 73, 67, 40]
[Avery, Zavier, Brian, Samuel, Ben]


Bubble Sort Swaps:
Names: 7
Grades: 5

Selection Sort Swaps:
Names: 3
Grades: 1


Enter students names and grades from (0 - 100)
Name-0: Xander
Grade-0: 80
Name-1: Avery
Grade-1: 34
Name-2: Brian
Grade-2: 92
Name-3: Dave
Grade-3: 83
Name-4: Sam
Grade-4: 90


[Xander, Avery, Brian, Dave, Sam]
Bubble sort by name:
Avery | 34
Brian | 92
Dave | 83
Sam | 90
Xander | 80
[34, 92, 83, 90, 80]
[Avery, Brian, Dave, Sam, Xander]


[34, 92, 83, 90, 80]
Bubble sort by grade:
Brian | 92
Sam | 90
Dave | 83
Xander | 80
Avery | 34
[92, 90, 83, 80, 34]
[Brian, Sam, Dave, Xander, Avery]


[Xander, Avery, Brian, Dave, Sam]
Selection sort by name:
Avery | 34
Brian | 92
Dave | 83
Sam | 90
Xander | 80
[34, 92, 83, 90, 80]
[Avery, Brian, Dave, Sam, Xander]


[34, 92, 83, 90, 80]
Selection sort by grade:
Brian | 92
Sam | 90
Dave | 83
Xander | 80
Avery | 34
[92, 90, 83, 80, 34]
[Brian, Sam, Dave, Xander, Avery]


Bubble Sort Swaps:
Names: 4
Grades: 5

Selection Sort Swaps:
Names: 4
Grades: 3
*/
