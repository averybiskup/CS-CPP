#include <iostream>
#include <string>

using namespace std;

struct node {
  int data;
  node *next;
};

class list {
  private:
  node *head, *tail;
  public:
    list() {
      head = NULL;
      tail = NULL;
    }
    list(int value);
    void insert_start(int);
    void display();
    void delete_first();
    void delete_last();
    void createnode(int);
 };

// Constructor starting with value
 list::list(int value) {
   // Create temp node
   node *temp = new node;

   // Set data of temp node to value
   temp->data = value;
   
   // Set next of temp node to NULL
   temp->next = NULL;

   // Set the head node to temp
   head = temp;
 }

void list::insert_start(int value) {

  // Create temp node
  node *temp = new node;

  // Setting temp data to value, and head
  temp->data = value;
  temp->next = head;

  // Setting head to temp
  head = temp;
}

void list::display() {

  // Setting temp to head
  node *temp = new node;
  temp = head;

  // While the head isn't NULL, move on and check the next one
  while(temp != NULL) {

    // Print out data
    cout << temp->data << "\n";

    // Change the temp to the next one.
    temp = temp->next;
  }
}

void list::delete_first() {

  // Temp node
  node *temp = new node;

  temp = head;

  // Head now is next
  head = head->next;

  // Now we delete temp
  delete temp;
}

void list::createnode(int value) {

  // Temp node
  node *temp = new node;

  // Setting temp node's value
  temp->data = value;
  temp->next = NULL;

  // Checking if head already exists
  if (head == NULL) {

    // Setting head and tail to temp, and temp to NULL
    head = temp;
    tail = temp;
    temp = NULL;
   } else {

    // Setting tail's next to temp
    tail->next = temp;
    tail = temp;
   }
}

void list::delete_last() {

  // Temp node
  node *current = new node;

  // Setting previous to a new node
  node *previous = new node;

  // Current node is head
  current = head;

  // While the head of the current node is not null
  while(current->next != NULL) {

    // Set previous to current node
    previous = current;

    // Switch current node to next node
    current = current->next;
  }

  tail = previous;

  // Set previous's next to NULL
  previous->next = NULL;

  // Delete current node.
  delete current;
 }
