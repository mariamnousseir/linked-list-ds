# linked-list-ds
A C++ singly‑linked list implementation for the stack

Mariam Nousseir did: 

1. Repository Setup:
include/LinkedList.h: Header file containing the definition of the LinkedList class and its Node structure.
include/LinkedList.tpp: Template file for the LinkedList class's implementation.
src/main.cpp: Contains the main program where the linked list is tested.

3. implemented functions: 
LinkedList()
~LinkedList()
isEmpty()
isFull()
getLength()
insertAtEnd(const char* data)
getDataAt(int index)
search(const char* value)
printList()
removeDuplicates()
makeCircular()

3. performed tests:
Test 1: Check if the list is empty initially
Expected Output: "Is list empty? Yes"

Test 2: Inserting tokens at the end of the list
Expected Output: "List after insertions: 5 + ( 3 * 3 )"

Test 3: Getting the length of the list
Expected Output: "Length of list: 7"

Test 4: Retrieve data at index 3
Expected Output: "Data at index 3: 3"

Test 5: Searching for the first occurrence of the token '+'
Expected Output: "Token '+' found at index: 1"

Test 6: Removing duplicate tokens
Expected Output:

"List after removing duplicates: 5 + ( 3 * )"

"Length after removing duplicates: 5"

Test 7: Making the list circular
Expected Output: "List after converting to circular: 5 + ( 3 * 3 )"

Test 8: Check if the list is full
Expected Output: "Is list full? No"

Test 9: Retrieve data at an out-of-bounds index (index 100)
Expected Output: "Correctly handled out of bounds request"


