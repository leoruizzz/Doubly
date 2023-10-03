#include <iostream>
#include "DoublyLinkedList.hpp" 

int main() {
    DoublylinkedList<int> myList;


    int d, i, c, newD;


    bool success;



    do {
        std::cout << "\nMenu" << std::endl;
        std::cout << "1 Add an element to the beginning of the list" << std::endl;
        std::cout << "2 Add an element to the end of the list" << std::endl;
        std::cout << "3 Insert an element to the right of the given index" << std::endl;
        std::cout << "4 Delete a given element from the list" << std::endl;
        std::cout << "5 Delete an element at a specified position in the list" << std::endl;
        std::cout << "6 Get the element at a given position in the list" << std::endl;
        std::cout << "7 Update a given element in the list" << std::endl;
        std::cout << "8 Update an element at a specified position in the list" << std::endl;
        std::cout << "9 Find a given element in the list" << std::endl;
        std::cout << "10 Get the element at a position in the list (operator [])" << std::endl;
        std::cout << "11 Update the element at a position in the list (operator [])" << std::endl;
        std::cout << "12 Copy a list with the data from another list (operator =) (Duplicate the list)" << std::endl;
        std::cout << "13 Clear the list" << std::endl;
        std::cout << "14 Sort the list (Use the sorting algorithm of your choice)" << std::endl;
        std::cout << "15 Duplicate the list (The list should contain each element twice)" << std::endl;
        std::cout << "16 Remove duplicate elements (Sort the list first)" << std::endl;
        std::cout << "17 Exit" << std::endl;
        std::cout << "\nSelect an option: ";
        std::cin >> c;

        switch (c) {
            case 17:
                std::cout << "\nTry again" << std::endl;
                break;
            case 1:
                std::cout << "\nEnter the value of the element: ";
                std::cin >> d;
                myList.addFirst(d);
                myList.print();
                break;
            case 2:
                std::cout << "\nEnter the value of the element: ";
                std::cin >> d;
                myList.addLast(d);
                myList.print();
                break;
            case 3:
                std::cout << "\nEnter the value of the element: ";
                std::cin >> d;
                std::cout << "\nEnter the index after which you want to insert the element: ";
                std::cin >> i;
                try {
                    myList.insert(i + 1, d);
                    myList.print();
                } catch(const out_of_range& e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                }
                break;
            case 4:
                std::cout << "\nEnter the value of the element you want to delete: ";
                std::cin >> d;
                success = myList.deleteData(d);
                if (success) {
                    std::cout << "Element deleted successfully." << std::endl;
                    myList.print();
                } else {
                    std::cout << "The element was not found in the list." << std::endl;
                }
                break;
            case 5:
                std::cout << "\nEnter the index of the element you want to delete: ";
                std::cin >> i;
                try {
                    myList.deleteAt(i);
                    myList.print();
                } catch(const out_of_range& e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                }
                break;
            case 6:
                std::cout << "\nEnter the index of the element you want to retrieve: ";
                std::cin >> i;
                try {
                    d = myList.getData(i);
                    std::cout << "Value: " << d << std::endl;
                } catch(const out_of_range& e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                }
                break;
            case 7:
                std::cout << "\nEnter the value of the element you want to update: ";
                std::cin >> d;
                std::cout << "\nEnter the new value of the element: ";
                std::cin >> newD;
                myList.updateData(d, newD);
                myList.print();
                break;
            case 8:
                std::cout << "\nEnter the index of the element you want to update: ";
                std::cin >> i;
                std::cout << "\nEnter the new value of the element: ";
                std::cin >> newD;
                try {
                    myList.updateAt(i, newD);
                    myList.print();
                } catch(const out_of_range& e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                }
                break;
            case 9:
                std::cout << "\nEnter the value of the element you want to find: ";
                std::cin >> d;
                i = myList.findData(d);
                if (i != -1) {
                    std::cout << "The element is at index: " << i << std::endl;
                } else {
                    std::cout << "The element was not found in the list." << std::endl;
                }
                break;
            case 10:
                std::cout << "\nEnter the index of the element you want to retrieve: ";
                std::cin >> i;
                try {
                    data = myList[i];
                    std::cout << "The value of the element is: " << data << std::endl;
                } catch(const out_of_range& e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                }
                break;
            case 11:
                std::cout << "\nEnter the index of the element you want to update: ";
                std::cin >> i;
                std::cout << "\nEnter the new value of the element: ";
                std::cin >> newD;
                try {
                    myList[i] = newD;
                    myList.print();
                } catch(const out_of_range& e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                }
                break;
            case 13: 
                myList.clear();
                std::cout << "\nList cleared." << std::endl;
                break;
            case 14:
                myList.sort();
                std::cout << "\nList sorted." << std::endl;
                myList.print();
                break;
            case 15:
                myList.duplicate();
                std::cout << "\nList duplicated." << std::endl; 
                myList.print();
                break;
            case 16:
                myList.removeDuplicates();
                std::cout << "\nDuplicate elements have been removed from the list." << std::endl;
                myList.print();
                break;
            default:
                if (c != 17) {
                    std::cerr << "\nError: Invalid choice. Please try again." << std::endl;
                }
                break;
        }
    } while (c != 17);

    return 0;
}
