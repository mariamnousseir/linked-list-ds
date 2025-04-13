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
     for (int i = 0; i < position - 1; i++) //traverse through the list till we reach the node before desired position n ode
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

