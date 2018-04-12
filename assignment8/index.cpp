#include <iostream>
#include <string>
#include <istream>

using namespace std;

// Address structure
struct Address {
  char *pStreet;
  char *pCity;
};

// Student structure
struct Student {
  char *pName;
  Address address;
  int nAge;
};

// Getting user information
void initializeData(Student * pStudents, int size) {
  // Creating dynamic C-strings
  const int MAXLENGTH = 100;
  char * name = new char[MAXLENGTH];
  char * street = new char[MAXLENGTH];
  char * city = new char[MAXLENGTH];
  for (int i = 0; i < size; i++) {
    cout << "Name: ";
    name = new char[MAXLENGTH];
    cin.getline(name, MAXLENGTH);

    cout << "\nStreet: ";
    street = new char[MAXLENGTH];
    cin.getline(street, MAXLENGTH);

    cout << "\nCity: ";
    city = new char[MAXLENGTH];
    cin.getline(city, MAXLENGTH);

    cout << "\nAge: ";
    int age = 0;
    cin >> age;

    cin.ignore();

    cout << endl;

    pStudents[i].pName = name;
    pStudents[i].address.pStreet = street;
    pStudents[i].address.pCity = city;
    pStudents[i].nAge = age;
  }

  // Deleting arrays
  delete[] street;
  delete[] city;
  delete[] name;

}

// Helper function for bubble sort
void swap(Student * p1, Student * p2) {
  Student temp = *p1;
  *p1 = *p2;
  *p2 = temp;
}

// Using bubble sort to sort by age
void sortData(Student * pStudents, int size) {
  int total = 0;

  do {
    total = 0;
    for (int i = 0; i < size; i++) {
      int firstNum, secondNum;
      firstNum = pStudents[i + 1].nAge;
      secondNum = pStudents[i].nAge;

      if (firstNum > secondNum) {
        swap(&pStudents[i], &pStudents[i+1]);
        total += 1;
      }
    }
  } while (total != 0);
}


// For printing out all of the data
void displayData(Student * pStudents, int size) {
  // getting average age
  float averageAge = 0;
  for (int i = 0; i < size; i++) {
    cout << "\n\nName: " << pStudents[i].pName << endl;
    cout << "Street: " << pStudents[i].address.pStreet << endl;
    cout << "City: " << pStudents[i].address.pCity << endl;
    cout << "Age: " << pStudents[i].nAge << endl;
    averageAge += pStudents[i].nAge;
  }
  cout << "\nAvererage Age: " << (averageAge / size) << endl;
}

int main() {
  cout << "How many students?\n>";
  int studentAmount = 0;
  cin >> studentAmount;
  cin.ignore();

  // Main array of structures
  Student * students = new Student[studentAmount];

  // Using the functions
  initializeData(students, studentAmount);

  sortData(students, studentAmount);

  displayData(students, studentAmount);

  delete[] students;
}


// Example

/*
How many students?
>3
Name: Avery

Street: Arguello

City: San Francisco

Age: 18

Name: Sam

Street: Haines

City: Seattle

Age: 14

Name: Mike

Street: Water

City: Port Townsend

Age: 48



Name: Mike
Street:
City: Port Townsend
Age: 48


Name: Avery
Street: Arguello
City: San Francisco
Age: 18


Name: Sam
Street: Haines
City: Seattle
Age: 14

Avererage Age: 26.6667
*/
