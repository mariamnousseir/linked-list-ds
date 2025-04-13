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

// Inserts a new node at the end of the list.
void LinkedList::insertAtEnd(const char* data) {
    Node* newNode = new Node(data);
    if (isEmpty()) {
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != nullptr && current->next != head) {
            current = current->next;
        }
        current->next = newNode;
    }
    length++;
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
struct Node {
    char data[100];  // Use fixed-size char array for simplicity
    Node* next;
};

Node* createNode(const char* data) {
    Node* newNode = new Node;
    strcpy(newNode->data, data);
    newNode->next = nullptr;
    return newNode;
}

void appendNode(Node*& head, const char* data) {
    if (head == nullptr) {
        head = createNode(data);
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = createNode(data);
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

Node* getPreviousNode(Node* head, Node* target) {
    if (head == nullptr || head == target)
        return nullptr;
    Node* current = head;
    while (current != nullptr && current->next != target)
        current = current->next;
    return current;
}

Node* getMiddleNode(Node* head) {
    if (head == nullptr)
        return nullptr;
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* getLastNode(Node* head) {
    if (head == nullptr) return nullptr;
    while (head->next != nullptr)
        head = head->next;
    return head;
}

Node* getNodeByData(Node* head, const char* targetData) {
    Node* current = head;
    while (current != nullptr) {
        if (strcmp(current->data, targetData) == 0)
            return current;
        current = current->next;
    }
    return nullptr;
}

Node* getHead(Node* head) {
    return head;
}

Node* getTail(Node* head) {
    if (head == nullptr)
        return nullptr;
    Node* current = head;
    while (current->next != nullptr)
        current = current->next;
    return current;
}

void freeList(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}