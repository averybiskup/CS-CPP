#include <iostream>
#include <string>

using namespace std;

void reverse(string s) {
  int length = s.size();
  if (length == 0) {
    ;
  } else {
    reverse(s.substr(1, length - 1));
    cout << s.substr(0, 1);
  }
}


int main() {

  reverse("cat");
}
