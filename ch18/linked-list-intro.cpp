#include <iostream>
#include <memory>

using namespace linked_list;

namespace linked_list {


/*Chapter 18 - Introduction to linked lists*/
struct Node {
    int data; // Data to hold in linked list element
    Node* next; // Pointer to the next node element
};

class ForwardLinkedList {
    public:
        void appendNode(double number) {
            Node* newNode;
            Node* currentNode; 

            newNode = new Node;
            newNode-> data = number;
            newNode->next = nullptr;

            // If there are no items in the list
            if (!headNode) 
                headNode = newNode;
            else {
                currentNode = headNode;
                while (currentNode->next) {
                    currentNode = currentNode->next;
                }
                // Insert newNode as last node
                currentNode->next = newNode;
            }            
        }

    private:
        Node* headNode; // First element in list

};


class ForwardSortedLinkedList {
    public:
        void appendNode(double number) {
            Node* newNode;
            Node* currentNode; 
            Node* previousNode;

            newNode = new Node;
            newNode-> data = number;
            newNode->next = nullptr;

            // If there are no items in the list
            if (!headNode) 
                headNode = newNode;
            else {
                // Traverse the list and compare values at each step
                currentNode = headNode;
                while (currentNode->next) {
                    previousNode = currentNode;
                    currentNode = currentNode->next;

                    // If the currentNode > newNode value
                    // Then insert newNode after previousNode
                    if (currentNode->data > newNode->data) {
                        previousNode->next = newNode;
                        newNode->next = currentNode;
                        return;
                    }

                    // If the currentNode < newNode value
                    // Then continue

                    // If there are no more nodes to traverse
                    // Then append node       
                }
                // Insert newNode as last node if we make it this far
                if (!currentNode->next) {
                    currentNode->next = newNode;
                }
                
            }            
        }

    private:
        Node* headNode; // First element in list

};


}; // End of namespace


int main () {
    
    // Create nodes
    Node* node1;
    Node* node2;
    Node* node3;

    node1 = new Node;
    node1->data = 1;
    node2 = new Node;
    node2->data = 2;
    node3 = new Node;
    node3->data = 3;

    node1->next = node2; // node1 is the 'tail'
    node2->next = node3; // node2 is in the middle
    // node3 is the 'head'

    // Alternatively I can just create one pointer and continually allocate
    Node* n;
    Node* t;
    Node* head;
    n = new Node; // Create a new node
    head = n;
    n->data = 1; // Assign data
    t = n; // Remember the previous node to link it
    n = new Node; // Create new node
    n->data = 2; // Assign data
    t->next = n; // Link previous node to new node
    t = n; // Remember the previous node to link it (1->2)
    n = new Node; // Create a new node
    n->data = 3; // Assign data
    t->next = n; // Link previous node to new node
    t = n; // Remember the previous node to link it (2->3)
    n = new Node; // Create a new node
    n->data = 4; // Assign data
    t->next = n; // Link previous node to new node
    t = n; // Remember the previous node to link it (3->4)
    /*... continue...*/


    return 0;
}