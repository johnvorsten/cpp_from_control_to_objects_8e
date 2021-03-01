#ifndef DynamicStack_H 
#define DynamicStack_H
#include <initializer_list>
#include <iostream>
#include <exception>

using namespace std;




// Structure for the stack nodes
template <typename T>
struct StackNode {
    T value; // Value in the node
    StackNode* next; // Pointer to the next node
    StackNode* previous; // Pointer to previous node
};


// Stack template 
template <typename T> 
class DynamicStack {

    private: 
    StackNode<T>* top = nullptr; // Pointer to top
    StackNode<T>* back = nullptr; // Pointer to back
    int length;

    public:

    // Constructor
    DynamicStack() : top(nullptr), back(nullptr), length(0) {}
    DynamicStack(std::initializer_list<T> T_list) : length(0) {
        // Create a node for each item in initializer_list
        for (auto& item : T_list) {
            push(item);
        }
    }

    // Destructor
    ~DynamicStack() {
        StackNode<T>* current_node;
        StackNode<T>* next_node;

        current_node = top;

        // Traverse and delete
        while (current_node) {
            next_node = current_node->next;
            delete current_node;
            current_node = next_node;
        }

    }

    // Operations
    void push(T t) {
        // Allocate new node
        StackNode<T>* new_node = nullptr;
        new_node = new StackNode<T>;
        new_node->value = t;

        if (is_empty()) {
            // No nodes currently in stack
            top = new_node;
            back = new_node;
            new_node->next = nullptr;
            new_node->previous = nullptr;
            length++;
        }
        else {
            // Current items in stack
            new_node->next = top;
            top->previous = new_node;
            top = new_node;
            length++;
        }

    }

    void push_back(T t) {
        // Allocate new node
        StackNode<T>* new_node = nullptr;
        new_node = new StackNode<T>;
        new_node->value = t;

        if (is_empty()) {
            // No nodes currently in stack
            top = new_node;
            back = new_node;
            new_node->next = nullptr;
            new_node->previous = nullptr;
            length++;
        }
        if (!top->next) {
            // Only one item in the stack
            back = new_node;
            back->previous = top;
            top->next = back;
            length++;
        }
        else {
            // Current items in stack
            // 1. Assign new node to back position
            new_node->previous = back;
            new_node->next = nullptr;
            // 2. Reassign back to be before new back
            back->next = new_node;
            back = new_node;
            length++;
        }
    }

    T pop() {
        StackNode<T>* temp = nullptr;
        T res;

        if (is_empty()) {
            // The stack is currently empty
            throw std::range_error("The stack is empty");
        }
        else if (top->next == nullptr) {
            // There is only one item in the stack
            // 1. Make copy
            res = top->value;
            // 2. Free memory
            delete top;
            // 3. Reset top and return
            top = nullptr;
            back = nullptr;
            length--;
            return res;
        }
        else {
            // Return the first item
            // 1. Make a copy
            temp = top;
            res = temp->value;
            // 1.X Remove reference back
            top->next->previous = nullptr;
            // 3. Reassign new top
            top = top->next;
            // 2. Release memory
            delete temp;
            // 4. Return
            length--;
            return res;
        }

    }

    T pop_back() {
        // Remove an element from the back of the stack
        StackNode<T>* temp;
        T res;

        if (is_empty()) {
            throw std::range_error("The stack is empty");
        }
        else if (top->next == nullptr) {
            // There is only one item in the stack
            // 1. Make copy
            temp = back;
            // 1.X Change backwards pointer (not necessary?)
            back->previous = nullptr;
            // 2. Free memory
            delete back;
            // 3. Reset top and return
            top = nullptr;
            back = nullptr;
            length--;
            return temp->value;
        }
        else {
            // There are multiple items in the stack
            // 1. Make a copy
            temp = back;
            res = back->value;

           // 2. Reassign new back
            back = back->previous;
            back->next = nullptr;

            // 3. Release memory
            delete temp;
 
            // 4. Return
            length--;
            return res;
        }

    }

    T peek_front() {
        /* Return the value of the front element, but do not remove anything 
        from the stack */

        if (is_empty()) {
            // The stack is currently empty
            throw std::range_error("The stack is empty");
        }
        else {
            // Sneak a peek
            return top->value;
        }

    }

    T peek_back() {
        /* Return the value of the back element, but do not remove anything 
        from the stack */

        if (is_empty()) {
            // The stack is currently empty
            throw std::range_error("The stack is empty");
        }
        else {
            // Sneak a peek
            return back->value;
        }

    }

    bool is_empty(){
        if (!top)
            // There is no pointer to the first item
            return true;
        else 
            return false;

        return false;
    }

    int get_length() {
        return length;
    }

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const DynamicStack<U>& dynstack);

};

template <typename U>
std::ostream& operator<<(std::ostream& os, const DynamicStack<U>& dynstack) {
    StackNode<U>* node = nullptr;
    node = dynstack.top;

    // Print stack to output
    os << "Printing stack structure" << std::endl;
    while (node->next) {
        os << node->value << "<-";
        node = node->next;
    }
    os << node->value << "|end|";
    os << "\n\n";

    return os;
}

#endif