#include "LinkedList.h"

int main() {
    cout << "Beginning LinkedList Data Structure Tests:" << endl;

    LinkedList list;

    cout << "\nTest 1: Check if list is empty initially:" << endl;
    cout << "Is list empty? " << (list.isEmpty() ? "Yes" : "No") << endl;

    cout << "\nTest 2: Inserting tokens at the end of the list:" << endl;
    list.insertAtEnd("5");
    list.insertAtEnd("+");
    list.insertAtEnd("(");
    list.insertAtEnd("3");
    list.insertAtEnd("*");
    list.insertAtEnd("3");
    list.insertAtEnd(")");
    cout << "List after insertions: ";
    list.printList();

    cout << "\nTest 3: Getting the length of the list:" << endl;
    cout << "Length of list: " << list.getLength() << endl;

    cout << "\nTest 4: Retrieve data at index 3:" << endl;
    char* dataAtIndex = list.getDataAt(3);
    if (dataAtIndex)
        cout << "Data at index 3: " << dataAtIndex << endl;

    cout << "\nTest 5: Searching for the first occurrence of token '+':" << endl;
    int foundIndex = list.search("+");
    if (foundIndex != -1)
        cout << "Token '+' found at index: " << foundIndex << endl;
    else
        cout << "Token '+' not found in the list." << endl;

    cout << "\nTest 6: Removing duplicate tokens:" << endl;
    list.removeDuplicates();
    cout << "List after removing duplicates: ";
    list.printList();
    cout << "Length after removing duplicates: " << list.getLength() << endl;

    cout << "\nTest 7: Making the list circular:" << endl;
    list.makeCircular();
    cout << "List after converting to circular: ";
    list.printList();

    cout << "\nTest 8: Check if list is full:" << endl;
    cout << "Is list full? " << (list.isFull() ? "Yes" : "No") << endl;

    cout << "\nTest 9: Retrieve data at an out of bounds index (index 100):" << endl;
    char* invalidData = list.getDataAt(100);
    if (invalidData == nullptr)
        cout << "Correctly handled out of bounds request" << endl;

    cout << "\nTest 10: Inserting tokens at the start of the list:" << endl;
    list.insertAtFront("4");
    list.insertAtFront("+");
    list.insertAtFront("(");
    list.insertAtFront("2");
    list.insertAtFront("*");
    list.insertAtFront("3");
    list.insertAtFront(")");
    cout << "List after insertions: ";
    list.printList();
    cout << "Length of list after insertions: " << list.getLength() << endl;

    cout << "\nTest 11: Inserting node with value \"3\" after node containing value \"2\":" << endl;
    // Assuming the node with "2" is at index 2 after Test 10 insertions:
    LinkedList::Node* nodeAt2 = list.getNodeAt(2);
    if (nodeAt2) {
        list.insertAfter(nodeAt2, "3");
    }
    cout << "List after insertion: ";
    list.printList();

    cout << "\nTest 12: Inserting node at position 2:" << endl;
    list.insertAtPosition(2, "20"); // insert "20" at position 2
    cout << "List after insertion: ";
    list.printList();

    cout << "\nTest 13: Swapping nodes with values at positions 3 and 5:" << endl;
    LinkedList::Node* nodeAt3 = list.getNodeAt(3);
    LinkedList::Node* nodeAt5 = list.getNodeAt(5);
    if(nodeAt3 && nodeAt5) {
        list.swapNodes(nodeAt3, nodeAt5);
    }
    cout << "List after swapping nodes: ";
    list.printList();

    cout << "\nAll Tests Completed" << endl;
    return 0;
}
