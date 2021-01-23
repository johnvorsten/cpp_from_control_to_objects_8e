#include <iostream>
#include <random>
#include <functional>

using namespace std;

// Function declarations
template <int rows>
double average_food(double (*array)[5], size_t rows) {
    double sum;
    size_t size;

    std::cout << __func__ << std::endl;

    for (auto& row : array) {
        for (auto& weight : row) {
            sum += weight;
            size++;
        }
    }
    auto average = (sum / size);

    return average;
}

double least_food(double (*array)[5], size_t rows) {
    auto minimum = monkey_food[0][0];

    for (auto& row : array) {
        for (auto& val : row) { 
            if (minimum < val)
                minimum = val;
        }
    }

    return minimum;
}

double maximum_food(double (*array)[5], size_t rows) {
    auto maximum = monkey_food[0];

    for (auto& row : array) {
        for (auto& val : row) {
            if (maximum > val)
                maximum = val;
        }
    }

    return maximum;
}

void user_input(double monkey_food[], int size) {
    // do something
}

// Class declarations

// Data declarations
/*Keep track of how many points of food each of (3) monkeys eat
rows - number of monkeys
columns - day of week (excluding weekends)*/
double monkey_food[3][5];


int main () {

    // Initialize array
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution;
    auto get_random = std::bind(distribution, generator );
    for (auto& row : monkey_food) {
        for (auto& val : row) {
            val = get_random();
        }   
    }



    return 0;
}