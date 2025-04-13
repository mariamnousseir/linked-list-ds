
#include <iostream>
#include "LinkedList.h"
#include "ReverseLinkedList.h"

using namespace std;

int main() {
    Node* head = nullptr;

    // Build the list with nodes containing numbers from 1 to 10
    for (int i = 1; i <= 10; i++) {
        string numberStr = to_string(i);
        appendNode(head, numberStr.c_str());
    }

    cout << "Original List:" << endl;
    printList(head);

    // --- Perform node checks BEFORE reversing ---

    // Target node (looking for "5")
    Node* target = head;
    while (target && strcmp(target->data, "5") != 0)
        target = target->next;

    Node* prevNode = getPreviousNode(head, target);
    if (target) {
        cout << "\nTarget node data = " << target->data << endl;
        if (prevNode)
            cout << "Previous node data = " << prevNode->data << endl;
        else
            cout << "Target node is head; no previous node." << endl;
    }

    // Middle node
    Node* middle = getMiddleNode(head);
    if (middle)
        cout << "\nMiddle node data = " << middle->data << endl;

    Node* lastFromEnd = getLastNode(head);
    if (lastFromEnd)
        cout << "\nLast node from end data = " << lastFromEnd->data << endl;
    else
        cout << "\nUnable to get last node from end." << endl;
    
    const char* targetData = "5";
    Node* nthNode = getNodeByData(head, targetData);
    if (nthNode)
        cout << "\nNode containing \"" << targetData << "\" found. Data = " << nthNode->data << endl;
    else
        cout << "\nNode containing \"" << targetData << "\" not found." << endl;

    // Head
    Node* headNode = getHead(head);
    if (headNode)
        cout << "\nHead data = " << headNode->data << endl;

    // Tail
    Node* tailNode = getTail(head);
    if (tailNode)
        cout << "\nTail data = " << tailNode->data << endl;

    // --- Reverse the list ---
    head = reverseList(head);
    cout << "\nReversed List:" << endl;
    printList(head);

    // --- Cleanup ---
    freeList(head);
    cout << "\nList memory freed." << endl;

    return 0;
}
