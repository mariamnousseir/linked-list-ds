#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node {
    char* data;
    Node* next;
};

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

#endif 
