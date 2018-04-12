#include <iostream>
#include <string>

using namespace std;

// Function for swapping two values
void swap(int * value1, int * value2, int temp) {
  temp = *value1;
  *value1 = *value2;
  *value2 = temp;
}

// Function for checking if a value is negative
 void noNegatives(int *x) {
   *x = (*x < 0) ? 0 : *x;
 }

int main() {
  int x = 0, y = 0;

  int * p1 = NULL;

  p1 = &x; // Set p1 to x's address
  *p1 = 99; // Change p1's value (x's address) to 99

  cout << x << endl; // Display value of x
  cout << *p1 << endl; // Display value of x by dereferencing pointer

  p1 = &y; // Set p1 to y's address
  *p1 = -300; // Change that adress value to -300

  int temp = 0;
  int * p2 = NULL;

  p2 = &x; // Set p2 to the address of x

  cout << x << " | " << y << endl; // Display values

  swap(p1, p2, temp); // Swapping the values at the pointers

  cout << x << " | " << y << endl;

  noNegatives(p1); // Checking for negative
  noNegatives(p2); // Checking for negative

  cout << *p2 << endl;
  swap(p1, p2, temp); // Swapping the values
  cout << *p2 << endl;
  swap(p1, p2, temp); // Swapping the values

  int a[2] = {0};

  a[0] = *p2; // Setting a[0] to the value of p2's address
  swap(p1, p2, temp); // Swapping the values
  a[1] = *p2; // Setting a[1] to the value of p2's address
  cout << a[0] << endl;
  cout << a[1] << endl;

  p1 = &a[0]; // Setting p1 to the address of a[0]
  p2 = &a[1]; // Setting p2 to the address of a[1]
  cout << *p1 << " | " << *p2 << endl;
  cout << a[0] << " | " << a[1] << endl;

  swap(p1, p2, temp); // Swapping values

  cout << x << " | " << y << endl;

  swap(&a[0], &a[1], temp); // Swapping values

  cout << a[0] << " | " << a[1] << endl;

}
