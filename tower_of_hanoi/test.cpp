#include <iostream>
#include <string>

using namespace std;

struct tower {
  int height;
  int a[8];
  int b[8];
  int c[8];
};

int len(int *t) {
  return (sizeof(t)/sizeof(*t)) + 1;
}

void moveDisc(tower *t, int *from[], int *to[]) {
  // cout << *(to) << endl;
  // (*to + height) = (*from);
  // (*to) = 0;
  // return t;
}


void printTower(tower t) {
  cout << "Height: " << t.height << endl;

  for (int i = 0; t.a[i] != 0 || i < t.height; i++) {
    cout << t.a[i] << " | " << t.b[i] << " | " << t.c[i] << endl;
  }
  cout << endl;
  cout << "A   B   C" << endl;
  cout << endl;
}

tower createTower(int height) {

  tower t = {
    height,
    {0},
    {0},
    {0}
  };

  for (int i = 1; i < height + 1; i++) {
    t.a[i -1] = i;
  }

  return t;
}

int main() {
  tower t = createTower(3);
  printTower(t);
  moveDisc(&t, &t.a, &t.b);
  printTower(t);
}
