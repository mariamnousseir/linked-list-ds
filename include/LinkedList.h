#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <new>
#include <stdexcept>
#include <cstring>

using namespace std;

class LinkedList {
public:
    // Make Node public so that test code can access it.
    struct Node {
        char* data;
        Node* next;
<<<<<<< HEAD
        Node* prevNode; // Preserved as in your original code, though not used.
        // Constructor that allocates memory and copies the string.
        Node(const char* val) : next(nullptr), prevNode(nullptr) {
            size_t len = strlen(val) + 1;
            data = new char[len];
=======
        Node* prevNode;
        // Constructor for Node that allocates memory and copies the string.
        Node(const char* val) : next(nullptr) {
            size_t len = strlen(val) + 1;
            data = new char[len];
            // Note: strcpy_s is Microsoft-specific.
            // If you are using gcc/clang, you can replace it with strcpy or strncpy.
>>>>>>> origin/main
            strcpy(data, val);
        }
    };

private:
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
<<<<<<< HEAD
    void insertAfter(Node* prevNode, const char* data);
    void insertAtPosition(int position, const char* data);
    void swapNodes(Node* node1, Node* node2);
=======
    void insertAfter(Node* prevNode,char *data);
    void insertAtPosition(int position,char *data);
    void swapNodes(Node*node1,Node*node2);
>>>>>>> origin/main
    char* getDataAt(int index) const;
    int search(const char* value) const;
    void printList() const;
    void removeDuplicates();
    void makeCircular();
    bool isCircular() const;
    void deleteAtHead();
    void deleteAtTail();
    void deleteAtPosition(int position);
<<<<<<< HEAD
    void deleteByValue(const char* value);
    // New helper function to obtain a node pointer by index (0-indexed)
    Node* getNodeAt(int index) const;
};

// The following global Node struct and functions are preserved from your original code.
struct Node {
    char data[100];  // Fixed-size character array
    Node* next;
};

=======
    void deleteByValue(char* value);
};
struct Node {
    char data[100];  // Fixed-size character array
    Node* next;
};

// Function declarations
>>>>>>> origin/main
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
<<<<<<< HEAD

=======
>>>>>>> origin/main
#include "LinkedList.tpp"

#endif // LINKEDLIST_H
