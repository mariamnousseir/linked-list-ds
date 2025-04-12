#include "LinkedList.h"

// Constructor
template<typename T>
LinkedList<T>::LinkedList()
  : head(nullptr), length(0) {}

// Destructor (empty for now)
template<typename T>
LinkedList<T>::~LinkedList() {
    // cleanup will go here later
}

// isEmpty
template<typename T>
bool LinkedList<T>::isEmpty() const {
    return head == nullptr;
}

// getLength
template<typename T>
int LinkedList<T>::getLength() const {
    return length;
}

// insertAtEnd
template<typename T>
void LinkedList<T>::insertAtEnd(const T& data) {
    Node* newNode = new Node(data);
    if (isEmpty()) {
        head = newNode;
    } else {
        Node* cur = head;
        while (cur->next) {
            cur = cur->next;
        }
        cur->next = newNode;
    }
    ++length;
}
