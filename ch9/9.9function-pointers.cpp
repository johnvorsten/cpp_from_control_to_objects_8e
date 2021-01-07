#include <iostream>
#include <vector>
#include <random>

using namespace std;

/*See this url for why I do not need to return a pointer to a new
vector instead of just returning by value
https://stackoverflow.com/questions/15704565/efficient-way-to-return-a-stdvector-in-c*/

// A function that returns a vector of random numbers
vector<float>* random_vector_generator(int n_elements) {
    // Get the pointer to a vector of n_elements
    std::vector<float>* random_vector = new std::vector<float>(n_elements); 

    // Create random number generators
    std::default_random_engine generator;
    std::weibull_distribution<float> distribution(2.0, 4.0);

    // Fill in memory
    for (int i=0;i < n_elements; i++) {
        // The -> operator is used with pointers to access a member
        // Function of a union or object
        random_vector->at(i) = distribution(generator);
    }

    return random_vector;
}

// A Function that returns an array of random numbers
float* random_array_generator(int n_elements) {
    float* random_array = nullptr;

    if (n_elements <= 0) {return nullptr;}

    // Allocate memory
    random_array = new float[n_elements];

    // Create random number generators
    std::default_random_engine generator;
    std::weibull_distribution<float> distribution(2.0, 4.0);

    // Fill in memory
    for (int i=0;i < n_elements; i++) {
        random_array[i] = distribution(generator);
    }

    return random_array;
}

int main () {

    std::vector<float>* myvectorptr = new vector<float>(5);
    std::vector<float> myvector = *myvectorptr;
    myvector[0] = 100.0;
    (*myvectorptr)[0] = 101.0; // Doesnt work - it doesn't access the = operator of the pointer?
    // *myvectorptr[0] = 101.0; // Invalid

    // Hmm...
    float* random_array_ptr = nullptr;
    random_array_ptr = random_array_generator(5);
    float& random_array = *random_array_ptr;
    for (int i=0; i < 5; i++) {
        std::cout << random_array_ptr[i] << " ";
    }

    std::vector<float>* random_vector_ptr = nullptr;
    random_vector_ptr = random_vector_generator(5);
    std::vector<float>& random_vector = *random_vector_ptr;
    
    // Free memory - cleanup
    delete [] random_array_ptr;
    delete random_vector_ptr;
    random_array_ptr = nullptr;
    random_vector_ptr = nullptr;


    return 0;
}