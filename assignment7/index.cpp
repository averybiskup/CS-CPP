#include <iostream>
#include <string>

using namespace std;

int lastIndexOf(char *s, char target) {
  int count = 0, last = 0;
  for (int i = 0; *(s + i) != '\0'; i++) {
    if (*(s + i) == target)
      last = count;
    count++;
  }
  if (last == 0 && *s != target)
    return -1;
  return last;
}

// Helper function to get length of a C-string
int getLength(char * s) {
  int count = 0;
  for (int i = 0; *(s + i) != '\0'; i++)
    count++;
  return count;
}

// Helper function for swapping two chars in a C-string
void swap(char * a, char * b) {
  char * temp = a;
  *a = *b;
  *b = *temp;
}

// Helper function for copying C-strings
void copyStr(char * a, char * b) {
  for (int i = 0; *(b + i) != '\0'; i++)
    *(a + i) = *(b + i);
}

// Comapares two strings to see if they are the same.
bool compare(char * s, char * b) {
  for (int i = 0; *(s + i) != '\0' && b[i] != '\0'; i++) {
    if (*(s + i) != *(b + i))
      return false;
  }
  return true;
}


// Function for reversing a string
void reverse(char *s) {
  char temp[400] = "";
  int n = 0;
  for (int i = getLength(s) - 1; i >= 0; i--) {
    swap((temp + n), (s + i));
    n++;
  }
  copyStr(s, temp);
}


// Function for replacing letters in a string with another char
int replace(char *s, char target, char replacementChar) {
  int count = 0;

  // Iterating through so we can replace
  for (int i = 0; *(s + i) != '\0'; i++) {
    if (*(s + i) == target) {
      *(s + i) = replacementChar;
      count++;
    }
  }

  return count;
}


// Function for finding a substring in a string
int findSubstring(char *s, char substring[]) {
  int count = 0;

  // Iterating through string
  for (int i = 0; *(s + i) != '\0'; i++) {

    // If the first letter of sub is same as main, we do a new for loop
    if (*(s + i) == substring[0]) {
      int matchCount = 0;

      // Making sure all the substring is in the string
      for (int n = 0; substring[n] != '\0'; n++) {
        if (*(s + i + n) == substring[n]) {
          matchCount++;
        }
        if (matchCount == getLength(substring)) {
          return count;
        }
      }
    }
    count++;
  }

  return -1;
}

// Function for checking if a string is a palindrome
// Basically, we just check if the string is the same before and after we reverse it.
bool isPalindrome(char *s) {
  char b[400] = "";
  copyStr(b, s);
  reverse(s);
  return compare(s, b);
}

// Function that helps the reverseWords function
void reverseSub(char * s, int start, int end) {
  char sub[30] = "";
  int n = 0;

  // Copying into new string
  for (int i = start; i < end; i++) {
    *(sub + n) = *(s + i);
    n++;
  }

  // Reverse word
  reverse(sub);
  n = 0;

  // Apply to main string
  for (int l = start; l < end; l++) {
    *(s + l) = *(sub + n);
    n++;
  }

}

// Function for reversing a sentence, but not the words
void reverseWords(char *s) {
  // First reverse the main string
  reverse(s);
  int startPoint = 0, endPoint = 0;
  for (int i = 0;; i++) {

    // Reverse each word in the sentence seperately
    if (*(s + i) == ' ' || *(s + i) == '\0') {
      endPoint = i;
      reverseSub(s, startPoint, endPoint);
      startPoint = endPoint + 1;
    }

    if (*(s + i) == '\0')
      break;
  }
}



int main() {

  // lastIndexOf function
  cout << "<--- Getting last index of char --->" << endl;
  char last[50] = "r h r h r h r h";
  cout << "String: " << last << endl;
  cout << "Returns: " << lastIndexOf(last, 'r') << endl;
  
  cout << endl;

  // reverse function
  cout << "<--- Reversing strings --->" << endl;
  char nombre[50] = "avery avery";
  cout << "String: " << nombre << endl;
  reverse(nombre);
  cout << nombre << endl;

  cout << endl;

  // replace function
  cout << "<--- Replacing chars --->" << endl;
  char replaceMe[50] = "avery avery avery avery";
  cout << "String: " << replaceMe << endl;
  cout << "Returns: " << replace(replaceMe, 'a', 'T') << endl;
  cout << replaceMe << endl;

  cout << endl;

  // findSubstring function
  cout << "<--- Finding sub string --->" << endl;
  char name[50] = "avary avery";
  char sub[50] = "ery";
  cout << "String: " << name << endl;
  cout << "Sub String: " << sub << endl;
  cout << "Returns: "<< findSubstring(name, sub) << endl;

  cout << endl;

  // isPalindrome function
  cout << "<--- Checking for palindrome --->" << endl;
  char is[50] = "hannah";
  char isNot[50] = "hannahs";
  cout << "hannah: " << isPalindrome(is) << endl;
  cout << "hannahs: " << isPalindrome(isNot) << endl;

  cout << endl;

  // reverseWords function
  cout << "<--- Reversing words --->" << endl;
  char test[50] = "The Giants won the Pennant!";
  cout << "String: " << test << endl;
  reverseWords(test);
  cout << test << endl;

  return 0;
}

// Example

/*
<--- Getting last index of char --->
String: r h r h r h r h
Returns: 12

<--- Reversing strings --->
String: avery avery
yreva yreva

<--- Replacing chars --->
String: avery avery avery avery
Returns: 4
Tvery Tvery Tvery Tvery

<--- Finding sub string --->
String: avary avery
Sub String: ery
Returns: 8

<--- Checking for palindrome --->
hannah: 1
hannahs: 0

<--- Reversing words --->
String: The Giants won the Pennant!
Pennant! the won Giants The
*/
