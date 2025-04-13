#include "LinkedList.h"

// Constructor
LinkedList::LinkedList() : head(nullptr), length(0) {}

// Destructor
LinkedList::~LinkedList() {
    if (head != nullptr) {
        Node* tail = head;
        while (tail->next != nullptr && tail->next != head) {
            tail = tail->next;
        }
        if (tail->next == head) {
            tail->next = nullptr;
        }
    }
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete[] temp->data;
        delete temp;
    }
}

// Checks if the list is empty
bool LinkedList::isEmpty() const {
    return (head == nullptr);
}

// Checks if the list is full by trying to allocate memory for a new node.
bool LinkedList::isFull() const {
    Node* temp = new (std::nothrow) Node("");
    if (temp == nullptr) {
        return true;
    }
    else {
        delete[] temp->data;
        delete temp;
        return false;
    }
}

// Returns the current length of the list.
int LinkedList::getLength() const {
    return length;
}


// Returns the data at a given index.
char* LinkedList::getDataAt(int index) const {
    if (index < 0 || index >= length) {
        cerr << "Error: index out of bounds" << endl;
        return nullptr;
    }
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

// Searches for the first occurrence of a given value and returns its index.
int LinkedList::search(const char* value) const {
    Node* current = head;
    int index = 0;
    while (current != nullptr && index < length) {
        if (strcmp(current->data, value) == 0) {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}

// Prints the list elements.
void LinkedList::printList() const {
    if (isEmpty()) {
        cout << "List is empty" << endl;
        return;
    }
    Node* current = head;
    int count = 0;
    while (current != nullptr && count < length) {
        cout << current->data << " ";
        current = current->next;
        count++;
    }
    cout << endl;
}

// Removes duplicate tokens from the list.
void LinkedList::removeDuplicates() {
    if (isEmpty()) {
        return;
    }
    Node* current = head;
    while (current != nullptr) {
        Node* runner = current;
        while (runner->next != nullptr && runner->next != head) {
            if (strcmp(runner->next->data, current->data) == 0) {
                Node* duplicate = runner->next;
                runner->next = duplicate->next;
                delete[] duplicate->data;
                delete duplicate;
                length--;
            }
            else {
                runner = runner->next;
            }
        }
        current = current->next;
        if (current == head) {
            break;
        }
    }
}

// Makes the linked list circular by connecting the last node to the head.
void LinkedList::makeCircular() {
    if (isEmpty()) {
        cerr << "Can't make an empty list circular" << endl;
        return;
    }
    Node* current = head;
    while (current->next != nullptr && current->next != head) {
        current = current->next;
    }
    current->next = head;
}

//function to check if list is circular
bool LinkedList::isCircular() const {
  if (isEmpty())
  {
    return false;
  }
  Node *current = head->next;
  if (current == head) {
    return true;
  }
  while(current!=nullptr)
    {
    if (current ==head){
      return true;
    }
    current = current->next;
    }
    return false;
}

//function to insert a new node at head
void LinkedList::insertAtFront(const char* data) {
 Node* newNode = new Node(data); //new node creation
 if (isEmpty()) //check if list is empty
 {
  head = newNode; //only one node
  }
  else
  {
  newNode->next = head; //new node point to head
  head = newNode; //update head to become the new node
  }
  length++; //increase list size
 }

 //function to insert a new node at the end.
void LinkedList::insertAtEnd(const char* data) {
    Node* newNode = new Node(data); //create new node
    if (isEmpty()) { //check if list is empty
        head = newNode; //only one node
    }
    else {
        Node* current = head; //otherwise traverse starting from head till last node to lti
        while (current->next != nullptr)
        {
            current = current->next; //traverse until we reach next = null
        }
        current->next = newNode; //insert new node at end
    }
    length++; //increase list size
}

//function to insert node after certain position
void LinkedList::insertAfter(Node*prevNode,char *data) {
  if(prevNode == nullptr) { //checks if there is a previous node or not
    cerr << "error: previous Node is null" << endl;
    return; //cannot insert after null
    }
    Node* newNode = new Node(data);  //create a new node
    newNode->next = prevNode->next; //new node points to next of previous node
    prevNode->next = newNode; //to link the previous node to the new node

    length++; //increase list size
}

//function to insert node at specific position
void LinkedList::insertAtPosition(int position,char* data) {
  if(position < 0 || position > length) //position not found
  {
    cerr << "error: position out of bounds" << endl;
  }
  if (position == 0) //if position is the first node(head)
    {
    insertAtFront(data);
    return;
    }
    if (position == length) //if position is the last node(tail)
      {
      insertAtEnd(data);
      return;
      }
      //if position is in between the list
     Node*current = head; //create a pointer to start from head
     for (int i = 0; i < position - 1; i++) //traverse through the list till we reach the node before desired position
       {
       current = current->next;
       }
       Node* newNode = new Node(data); //create new node
       newNode->next = current->next; //next of new node points to position
       current->next = newNode; //new node inserted at position

       length++;
}

//function to swap two nodes
void LinkedList::swapNodes(Node*node1,Node*node2) {
  //if two values are the same, no need to swap
  if (node1->data == node2->data)
    return;
  Node*current=head; //create a new pointer

  //swap the next pointers of each node
  current->next=node1->next;
  node1->next=node2->next;
  node2->next=node1->next;
}

//deleting first node (head)
void LinkedList::deleteAtHead(){
  if (isEmpty()){ //checking if list is empty
    cerr << "error: list is empty,nothing to delete" << endl;
    }
    Node* current = head; //create a pointer that points to the head
    head = head->next; //update the head to be the second node (the next of the previous head)
    delete current; //delete current (which was the previous head)
    length--; //modify the length by decreasing
  }

  //deleting last node (tail)
  void LinkedList::deleteAtTail(){
    if (isEmpty()){ //check if list is empty
      cerr << "error: list is empty,nothing to delete" << endl;
    }
    if (head->next == nullptr){ //check if the list had only one node
      delete head; //delete the only node in the list (head)
      head = nullptr; // modify the list to be empty
      length--; //modify the length by decreasing
    }
    Node* current = head; //create a pointer (current) that points to the head
    while (current->next != nullptr) //traverse through the list until current is standing at last node
    {
      current = current->next;
    }
    delete current; //to delete last node
    current = nullptr; //last node deleted
    length--;
    }

    //deleting at a specific position
    void LinkedList::deleteAtPosition(int position){
    if(isEmpty()){ //check if list is empty
      cerr << "error: list is empty,nothing to delete" << endl;
      return;
    }
    if(position < 0 || position > length){ //check if position is less or more than the current length of the list
      cerr << "error: position out of bounds" << endl;
      return;
    }
    if (position == 0){ //check if desired position is the head
      deleteAtHead(); //reuse the delete at head function
      return;
      length--; //modify the length by decreasing
    }
    if (position == length){ //check if desired position is the tail
      deleteAtTail(); //reuse the delete at tail function
      return;
      length--; //modify the length by decreasing
    }
    //in case the required position is the middle of the list
    Node*current = head; //create a pointer (current) pointing to the head
    //a loop to traverse through the list till we reach the node preceeding the desired position
    for (int i = 0; i < position - 1; i++){
      current = current->next;
      }
    Node* previous = current; //create a pointer that points to the node preceeding the required position
    previous = current->next->next; //let the pointer before the node that requires deletion point to the node following the one required deletion (pointers modification)
    delete current->next; //delete node at desired position

    length--; //modify the length by decreasing
    }
    //deleting a node by desired value
    void LinkedList::deleteByValue(char* value){
      if(isEmpty()){ //check if list is empty
        cerr << "error: list is empty,nothing to delete" << endl;
        return;
      }
      if(head->data == value){  //check if desired value is at head
        Node* current = head; //create a pointer to point at head
        head = head->next; //let the second node be the head
        delete current; //delete the previous head (desired value)
        length--; //modify the length by decreasing
        return;
      }
      Node* current = head; //create a pointer that points to the head
      while (current->next != nullptr && current->next->data != value){ //traverse through the list till the desired value is found or till null is reached
        current = current->next;
        }
        if (current->next == nullptr){ //if null is reached then value does not exist
          cerr << "error: node does not exist, desired value is not found" << endl;
          return;
        }
        if (current->next->data == value){ //if value is found
        Node* current2 = current->next; //create new pointer that points to the desired value
        current->next = current->next->next; //let the first pointer point to the next of the desired value
        delete current2->next; //delete the desired node
        length--; //modify the length by decreasing
        }
      }







