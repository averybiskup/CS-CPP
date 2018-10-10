#include <iostream>
#include <string>
#include "list.cpp"

using namespace std;

int main() {
  list l;

  l.createnode(5);
  l.insert_start(4);
  l.createnode(6);

  l.display();

  return 0;

}
