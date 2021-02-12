#include <memory>
#include <iostream>
#include <exception>
#include <string>
// #include <format>
#include <cassert>

using namespace std;

namespace linked_list {

/*Chapter 18 - Introduction to linked lists*/
struct Node {
    double data; // Data to hold in linked list element
    Node* next; // Pointer to the next node element
};

class ForwardSortedLinkedList {

    public:
        int length = 0; // Number of nodes in linked list

        ForwardSortedLinkedList(std::initializer_list<double> l) { // Initializer
            for (auto& val : l) {
                insertNode(val);
            }
        }

        ~ForwardSortedLinkedList() { // Empty memory
            Node* iterator = headNode;
            while (iterator != 0) {
                headNode = iterator->next;
                delete iterator;
                iterator = headNode;
            }
        }

        void insertNode(double number) {
            Node* newNode = nullptr;
            Node* currentNode = nullptr; 
            Node* previousNode = nullptr;

            newNode = new Node;
            newNode-> data = number;
            newNode->next = nullptr;

            // If there are no items in the list
            if (!headNode) {
                headNode = newNode;
                update_length();
                return;
            }
            else {
                // Traverse the list and compare values at each step
                currentNode = headNode;
                previousNode = headNode;

                // Test head case
                if (currentNode->data >= newNode->data) {
                    // Reassign head
                    newNode->next = headNode;
                    headNode = newNode;
                    update_length();
                    return;
                }
                // Other case
                while (currentNode->next) {

                    // If the currentNode > newNode value
                    // Then insert newNode after previousNode
                    if (currentNode->data >= newNode->data) {
                        previousNode->next = newNode;
                        newNode->next = currentNode;
                        update_length();
                        return;
                    }

                    // If the currentNode < newNode value
                    // Then continue (no action)
                    else if (currentNode->data < newNode->data) {
                        // Nothing
                    }

                    previousNode = currentNode;
                    currentNode = currentNode->next;
                }
                // Insert after last node
                if (!currentNode->next && currentNode->data < newNode->data) {
                    currentNode->next = newNode;
                    update_length();
                    return;
                }
                // Insert before last node
                else if (!currentNode->next && currentNode->data > newNode->data) {
                    newNode->next = currentNode;
                    previousNode->next = newNode;
                    update_length();
                    return;
                }
            }            
        }

        double pop(int index) {
            /*Remove a node at index from the list
            inputs
            -------
            index - index of node to remove. This is a forward linked list. 
                index should be 0 >= index >= length 
            output
            -------
            value of data within the node that was removed*/
            double value = 0;
            int count =0;
            Node* currentNode = headNode;
            Node* previousNode = nullptr;

            // index out of range
            if (index > (length - 1) || index < 0) {
                std::string msg;
                if (index < 0) {
                    msg += "The requested index ";
                    msg += index;
                    msg += " must be greater than zero";
                }
                else if (index > length) {
                    msg += "The requested index ";
                    msg += index;
                    msg += " is greater than the list length";
                }
                throw std::out_of_range(msg);
            }

            if (index == 0 && headNode->next) {
                // Return first element and fix link
                value = currentNode->data;
                headNode = headNode->next;
                delete currentNode;
                update_length();
                return value;
            }
            else if (index == 0 && !headNode->next) {
                // Return first element and set null link
                value = currentNode->data;
                headNode = nullptr;
                update_length();
                return value;
            }

            // Iterate through list until count == index
            while (count < index && currentNode->next) {
                previousNode = currentNode;
                currentNode = currentNode->next;
                count++;
            }
            // End of list
            if (!currentNode->next && count != index) {
                // Index is not end of list and we encounter non-linked node
                // Bad
                throw std::logic_error("Something is fucky"
                    " Index is not end of list and we encounter non-linked node");
            }
            else if (!currentNode->next && count == index) {
                // Index is at the end of the list and index last node
                // OK
                previousNode->next = nullptr;
                value = currentNode->data;
                delete currentNode;
            }
            else if (currentNode->next && count!= index) {
                // Node is linked but we fucked up the counting
                throw std::logic_error("Something is fucky"
                    " Node is linked but we fucked up the counting");
            }
            else {
                // Node is linked and we didn't fuck up counting
                // OK
                // Store (n+1) node
                previousNode->next = currentNode->next; // Link previous to next
                value = currentNode->data; // Return value
                delete currentNode; // Free memory
            }

            update_length();
            return value;
        }

        int search(double test) {
            /*Return the position of the first node in the list that stores data equal
            to test. 
            inputs
            -------
            test : value to search for in linked list
            outupt
            -------
            integer representing index of node within list where test==node.data*/
            int index = 0;
            Node* currentNode = headNode;

            // Empty list
            if (!headNode)
                return -1;
            else if (test == headNode->data)
                return 0;
            else {
                while (currentNode->next && test != currentNode->data) {
                    currentNode = currentNode->next;
                    index++;
                }

                if (currentNode->next && test == currentNode->data) {
                    // OK - item found in middle of list
                    return index;
                }
                else if (currentNode->next && test != currentNode->data) {
                    // Bad
                    throw std::logic_error("Something is fucky");
                }
                else if (!currentNode->next && test == currentNode->data) {
                    // OK - end of list and item found
                    return index;
                }
                else // (!currentNode->next && test != currentNode->data)
                    // OK - item not found in list
                    return -1;
            }

            return -1;
        }

        bool is_empty() {
            /*output
            -------
            boolean if list is empty*/
            if (!headNode && length == 0)
                return true;
            
            return false;
        }

        // Operator << 
        // std::ostream& operator<<(std::ostream& os) {
        //     // write object to stream
        //     Node* currentNode = headNode;
        //     while (currentNode->next) {
        //         os << currentNode->data;
        //         currentNode = currentNode->next;
        //     }
        //     return os;
        // }
        friend ostream& operator<<(ostream& os, const ForwardSortedLinkedList& list);

        // Operator []
        double operator[](int index) {

            // index out of range
            if (index > (length - 1) || index < 0) {
                std::string msg;
                if (index < 0) {
                    msg += "The requested index ";
                    msg += index;
                    msg += " must be greater than zero";
                }
                else if (index > length) {
                    msg += "The requested index ";
                    msg += index;
                    msg += " is greater than the list length";
            }
                throw std::out_of_range(msg);
            }

            Node* currentNode = headNode;
            int count = 0;

            while (currentNode->next && count < index) {
                currentNode = currentNode->next;
                count++;
            }

            return currentNode->data;
        }


    private:
        Node* headNode = nullptr; // First element in list
        Node* tailNode = nullptr; // Last element in list

        void update_length() {
            Node* currentNode = headNode;
            int count = 0;

            if (!headNode)
                length = 0;
            else if (!headNode->next)
                length = 1;
            else {
                count += 1;
                while (currentNode->next) {
                currentNode = currentNode->next;
                count++;
                }
                length = count;
            }
        }


};

std::ostream& operator<<(ostream& os, const ForwardSortedLinkedList& list) {
    Node* currentNode = list.headNode;
    std::cout << "Printing linked list" << endl;
    
    do {
        os << currentNode->data << "->";
        currentNode = currentNode->next;
    } while (currentNode);

    return os;
}


}; // End of namespace


void test_initializer() {
    std::cout << "Beginning " << __func__ << endl;

    linked_list::ForwardSortedLinkedList list{1,2,3,4,5};
    assert(list[0] == 1);
    assert(list[1] == 2);
    assert(list[4] == 5);

    std::cout << "Success - Passed " << __func__ << "\n\n";
}

void test_search() {
    std::cout << "Beginning " << __func__ << endl;

    linked_list::ForwardSortedLinkedList list{1,2,3,4,5};

    // Positive tests
    auto index0 = list.search(1);
    auto index1 = list.search(3);
    auto index2 = list.search(4);
    auto index3 = list.search(5);
    assert(index0 == 0);
    assert(index1 == 2);
    assert(index2 == 3);
    assert(index3 == 4);

    // Negative tests
    index0 = list.search(-1.254);
    index1 = list.search(3.000023);
    index2 = list.search(4.99);
    index3 = list.search(10);
    assert(index0 == -1);
    assert(index1 == -1);
    assert(index2 == -1);
    assert(index3 == -1);

    std::cout << "Success - Passed " << __func__ << "\n\n";

}

void test_insert() {
    std::cout << "Beginning " << __func__ << endl;

    linked_list::ForwardSortedLinkedList list{1,2,3,4,5};

    // Insert values
    list.insertNode(-1); // This does not work - need to insert before first
    assert(list[0] == -1);

    list.insertNode(0.01);
    assert(list[1] == 0.01);

    list.insertNode(1.00);
    assert(list[2] == 1.00);

    list.insertNode(1.05);
    assert(list[4] == 1.05);

    list.insertNode(2.00);
    assert(list[5] == 2.00);

    list.insertNode(2.01);
    assert(list[7] == 2.01);

    list.insertNode(10.0);
    assert(list[11] == 10.0);

    assert(list[0] == -1);
    assert(list[1] == 0.01);
    assert(list[2] == 1.00);
    assert(list[3] == 1.00);
    assert(list[4] == 1.05);
    assert(list[5] == 2.00);
    assert(list[6] == 2.00);
    assert(list[7] == 2.01);
    assert(list[8] == 3.00);
    assert(list[9] == 4.00);
    assert(list[10] == 5.0);
    assert(list[11] == 10.0);

    try {
        // Do something
    } catch (const std::logic_error& e) {
        // Print something
    }

    std::cout << "Success - Passed " << __func__ << "\n\n";
}

void test_pop() {
    std::cout << "Beginning " << __func__ << endl;

    // Initialize
    linked_list::ForwardSortedLinkedList list{1,2,3,4,5};

    // Pop first element
    auto val = list.pop(0);
    assert(val == 1.0);

    // middle element
    val = list.pop(1);
    assert(val == 3.0);

    // last element
    val = list.pop(2);
    assert(val == 5.0);

    // Insert then first {2,4}
    list.insertNode(0); // {0,2,4}
    val = list.pop(0);
    assert(val == 0);

    // Insert then middle
    list.insertNode(2.5); // {2, 2.5, 4}
    val = list.pop(1);
    assert(val == 2.5);

    // Insert then last
    list.insertNode(10); // {2, 4, 10}
    val = list.pop(2);
    assert(val == 10);

    // Should raise an exception
    try {
        std::cout << "Testing range exception underrange" << endl;
        list.pop(-1);
    } catch (const std::logic_error& e) {
        std::cout << "Success - Rasied: " << e.what() << endl;
    }
    try {
        std::cout << "Testing range exception overrange" << endl;
        list.pop(list.length + 10);
    } catch (const std::logic_error& e) {
        std::cout << "Success - Rasied: " << e.what() << endl;
    }
    std::cout << "Success - Passed " << __func__ << "\n\n";

}

void test_index_operator() {
    std::cout << "Testing index operator" << endl;

    // Initialize
    linked_list::ForwardSortedLinkedList list{1,2,3,4,5};

    // First element
    assert(list[0] == 1.0);
    // Middle element
    assert(list[2] == 3.0);
    // Last element
    assert(list[4] == 5.0);

    // Insert then first 
    list.insertNode(0); // {0,1,2,3,4,5}
    assert(list[0] == 0);

    // Insert then middle
    list.insertNode(2.5); // {0,1,2,2.5,3,4,5}
    assert(list[3] == 2.5);

    // Insert then last
    list.insertNode(10); // {0,1,2,2.5,3,4,5,10}
    assert(list[7] == 10);

    // Should raise an exception
    try {
        std::cout << "Testing range exception underrange" << endl;
        list[-1];
        std::cout << "Something is fucky " << __func__ << endl;
        assert(false);
    } catch (const std::logic_error& e) {
        std::cout << "Success - Rasied: " << e.what() << endl;
    }
    try {
        std::cout << "Testing range exception overrange" << endl;
        std::cout << list[10];
        std::cout << "Something is fucky " << __func__ << endl;
        assert(false);
    } catch (const std::logic_error& e) {
        std::cout << "Success - Rasied: " << e.what() << endl;
    }
}

void test_length() {

    linked_list::ForwardSortedLinkedList list{1,2,3,4,5};

    // Middle
    assert(list.length == 5);
    // End
    list.insertNode(10.01);
    assert(list.length == 6);
    // Beginning
    list.insertNode(0);
    assert(list.length == 7);

    try {
        // Do something
    } catch (const std::logic_error& e) {
        // Print something
    }
}


int main () {

    // Create a linked list
    linked_list::ForwardSortedLinkedList list{1,2,3,4,5};
    std::cout << list << endl;

    // Test length
    test_length();

    // Test initializer - good
    test_initializer();

    // Test search - good
    test_search();

    // Test insert - bad
    test_insert();

    // Test pop
    test_pop();

    // Test [] operator
    test_index_operator();


    return 0;
}