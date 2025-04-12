#include <iostream>
#include "LinkedList.h"

int main() {
    LinkedList<int> list;
    std::cout << "Empty? " << (list.isEmpty() ? "yes" : "no") << "\n";

    list.insertAtEnd(5);
    list.insertAtEnd(10);
    std::cout << "Length: " << list.getLength() << "\n";

    return 0;
}
