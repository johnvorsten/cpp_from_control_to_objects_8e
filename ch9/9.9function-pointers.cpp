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

void minMax(int a, int b, int c, int* big, int* small) {
	
	if (a > b && a > c)
		*big = a;
	else if (b > a && b > c)
		*big = b;
	else if (c > a && c > b)
		*big = c;
	
	if (a < b && a < c)
		*small = a;
	else if (b < a && b < c)
		*small = b;
	else if (c < a && c < b)
		*small = c;
	
}

void doubleIt(double* x) {
	*x *= 2;
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


    {
        /*MPL 10676*/
        int a=31, b=5, c=19, big=0, small=0;
        minMax(a, b, c, &big, &small);
        std::cout << big << endl;

        double x = 20.0;
        doubleIt(&x);

    }

    {
        /*MPL 10790*/
        int** abcs = nullptr;
        int** ip_arr = new int*[20];
        int** ip_arr2 = new int*[20];

        int int_arr[20]; // Declare a new array
        int* integer_pointer = nullptr; // Pointer
        int** integer_pointer_array = nullptr; // Pointer to a pointer
        integer_pointer_array = new int*[20]; // Pointer to array of 20 pointers

        // Assign a value to each pointer in the pointer array
        for (int i = 0; i < 20; i++) {
            (integer_pointer_array[i]) = new int;
        }

        // For the website
        for (int i = 0; i < 20; i++) {
            ip_arr[i] = new int;
        }

        // Allocate an array of 100 integer pointers and assign the resulting 
        // pointer to the appropriately declared variable, ip_arr. Allocate 100 
        // integers and assign the resulting pointers to the elements of ip_arr. 
        // Initialize each integer value to -1.
        int** ip_arr = nullptr;
        ip_arr = new int*[100];
        for (int i=0; i<100; i++) {
            ip_arr[i] = new int(-1);

        }


    }

    return 0;
}