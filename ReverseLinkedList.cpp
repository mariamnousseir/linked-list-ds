#include "ReverseLinkedList.h"
#include <iostream>
#include <cstring> 
using namespace std;

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
