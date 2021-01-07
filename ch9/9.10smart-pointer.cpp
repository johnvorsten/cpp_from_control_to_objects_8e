#include <iostream>
#include <memory>
#include <fstream>
#include <functional>
#include <cassert>
#include <cstdio>
#include <vector>

using namespace std;

struct B {
    virtual void bar() { std::cout << "B::bar\n"; }
    virtual ~B() = default;
};

struct D : B { // Class structure D inherits from B ?
    D() {std::cout << "D::D\n"; }
    ~D() { std::cout << "D:~D\n"; }
    void bar() override { std::cout << "D::bar\n"; } // override the var method of B
};

// A function consuming a unique_ptr can take it by value or rvalue reference?
std::unique_ptr<D> pass_through(std::unique_ptr<D> p) {
    p->bar(); // Call the bar method of the pointers object
    return p;
}

void close_file(std::FILE* fp) { std:fclose(fp); }

// Unique pointer based linked list for demo
struct List { // Linked list
    struct Node { // Node in linked list
        int data; // Each node can hold data
        std::unique_ptr<Node> next; // Define a pointer to the next item in the list
        Node(int data) : data{data}, next{nullptr} {} // Constructor?
    };

    List() : head{nullptr} {}; // Constructor?
    ~List() { while(head) head = std::move(head->next); } // Destructor?
    void push(int data) { // Insert data to list?
        auto temp = std::make_unique<Node>(data); // Pointer (temporary) to a node
        if(head) temp->next = std::move(head); // Head is the last element in the list
        head = std::move(temp); // Make the head point to the next element?? Not sure what std::move does
            // The way I understand it is we reassign the head pointer to the next element
            // std::move retruns a pointer to the element
    }

    private:
        std::unique_ptr<Node> head;
};


int main () {

    // Create a pointer that will be removed when no longer being used
    unique_ptr<int> ptr( new int );
    std::cout << "Value of dynamic pointer : " << *ptr << endl;

    // Dynamically allocated array
    unique_ptr<int[]> ptr2( new int[100]);
    std::cout << "Access array smart pointer elements directly : " << ptr2[0] << endl;


    // Demonstrate smart pointers
    std::cout << "Unique ownership semantics demo\n";
    {
        auto p = std::make_unique<D>(); // p is a pointer that owns D
        auto q = pass_through(std::move(p)); // pass an R value reference to the function
        // The function calls the objects bar() method
        // Difference between calling with an R value or by value??
        assert(!p); // p now owns nothing!! q owns the object
        q->bar(); // q owns the D object
    } // D Called here

    std::cout << "Runtime polymorphism demo\n";
    {
        std::unique_ptr<B> p = std::make_unique<D>(); // p is a unique_ptr that owns a D
        // as a pointer to base
        p->bar(); // virtual dispatch??

        std::vector<std::unique_ptr<B>> v; // unique_ptr can be stored in container
        v.push_back(std::make_unique<D>());
        v.push_back(std::move(p));
        v.emplace_back(new D);
        for (auto& p: v) p->bar(); // Virtual dispatch
    } // D called 3 times

    std::cout << "Custom deleter demo\n";
    std::ofstream("demo.txt") << 'x'; // Prepare to read file
    {
        std::unique_ptr<std::FILE, decltype(&close_file)> fp(std::fopen("demo.txt", "r"), 
            &close_file);
        if(fp) // fopen could have failed, in which case fp holds a null pointer
            std::cout << (char)std::fgetc(fp.get()) << '\n';
    } // fclose() called here, but only if FILE* is not a null pointer
        // (that is, if fopen succeeded)
    
    std::cout << "Custom lambda-expression deleter demo\n";
    {
        std::unique_ptr<D, std::function<void(D*)>> p(new D, [](D* ptr)
            {
                std::cout << "Destroying from custom deleter...\n";
                delete ptr;
            });
        p->bar();
    } // the lambda above is now called and D is destroyed

    std::cout << "Array form of unique_ptr demo\n";
    {
        std::unique_ptr<D[]> p{new D[3]};
    } // Call D three times

    std::cout << "Linked list demo\n";
    {
        List l;
        for (long n=0; n != 1'000'000; ++n) {
            l.push(n); 
        } // Destroys all 1 million nodes
    }
    return 0;
}