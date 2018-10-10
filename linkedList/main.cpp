#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

struct tod {
  int h;
  int m;
  int s;
  char d[32];
  tod *next;
  void todSet(int h, int m, int s, string d);
  void coutTod();
};

void tod::todSet(int h, int m, int s, string d) {
  this->h = h;
  this->m = m;
  this->s = s;
  strcpy(this->d, d.c_str());
}

void tod::coutTod() {
// Function to print times and description in the object.
   cout << h << ':';
   if (m < 10) {
     cout << '0'; cout << m << ':';
   } else {
     cout << m << ':';
   }


   if (s < 10) {
     cout << '0'; cout << s << endl;
   } else {
     cout << s << endl;
   }

   cout << d << endl;
}



int main() {
  tod t;
  // char input_string[32] = "testing";
  // getline(cin, input_string);
  t.todSet(5, 5, 5, "test");
  t.coutTod();
  return 0;
}
