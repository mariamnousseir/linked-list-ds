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

    cout << "\nAll Tests Completed" << endl;
    return 0;
}
