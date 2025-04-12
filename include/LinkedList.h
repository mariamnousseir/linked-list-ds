#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdexcept>

template<typename T>
class LinkedList {
private:
    struct Node {
        T      data;
        Node*  next;
        Node(const T& val) : data(val), next(nullptr) {}
    };
    Node* head;
    int   length;

public:
    LinkedList();
    ~LinkedList();

    bool isEmpty() const;
    int  getLength() const;

    void insertAtEnd(const T& data);
    // (we’ll add more methods later)
};

// Include the template implementation
#include "LinkedList.tpp"
#endif
