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
        // Constructor for Node that allocates memory and copies the string.
        Node(const char* val) : next(nullptr) {
            size_t len = strlen(val) + 1;
            data = new char[len];
            // Note: strcpy_s is Microsoft-specific.
            // If you are using gcc/clang, you can replace it with strcpy or strncpy.
            strcpy(data, val);
        }
    };
    Node* head;
    int length;
public:
    LinkedList();
    ~LinkedList();

    bool isEmpty() const;
    bool isFull() const;
    int getLength() const;
    void insertAtEnd(const char* data);
    char* getDataAt(int index) const;
    int search(const char* value) const;
    void printList() const;
    void removeDuplicates();
    void makeCircular();
};
struct Node {
    char data[100];  // Fixed-size character array
    Node* next;
};

// Function declarations
Node* createNode(const char* data);
void appendNode(Node*& head, const char* data);
void printList(Node* head);
Node* reverseList(Node* head);
Node* getPreviousNode(Node* head, Node* target);
Node* getMiddleNode(Node* head);
Node* getLastNode(Node* head);
Node* getNodeByData(Node* head, const char* targetData);
Node* getHead(Node* head);
Node* getTail(Node* head);
void freeList(Node* head);
#include "LinkedList.tpp"

#endif // LINKEDLIST_H
