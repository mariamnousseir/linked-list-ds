#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <new>
#include <stdexcept>
#include <cstring>

using namespace std;

class LinkedList {
private:
    struct Node {
        char* data;
        Node* next;
        Node* prevNode;
        // Constructor for Node that allocates memory and copies the string.
        Node(const char* val) : next(nullptr) {
            size_t len = strlen(val) + 1;
            data = new char[len];
            // Note: strcpy_s is Microsoft-specific.
            // If you are using gcc/clang, you can replace it with strcpy or strncpy.
            strcpy_s(data, len, val);
        }
    };
    Node* head;
    //Node* tail;
    int length;
public:
    LinkedList();
    ~LinkedList();

    bool isEmpty() const;
    bool isFull() const;
    int getLength() const;
    void insertAtFront(const char* data);
    void insertAtEnd(const char* data);
    void insertAfter(Node* prevNode,char *data);
    void insertAtPosition(int position,char *data);
    void swapNodes(Node*node1,Node*node2);
    char* getDataAt(int index) const;
    int search(const char* value) const;
    void printList() const;
    void removeDuplicates();
    void makeCircular();
    bool isCircular() const;
    void deleteAtHead();
    void deleteAtTail();
    void deleteAtPosition(int position);
    void deleteByValue(char* value);
};

#include "LinkedList.tpp"

#endif // LINKEDLIST_H
