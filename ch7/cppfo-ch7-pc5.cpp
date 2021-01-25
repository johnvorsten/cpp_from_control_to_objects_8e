#include <iostream>
#include <random>
#include <functional>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>

using namespace std;

// Data declarations
vector<string> week_string {"Sunday", "Monday","Tuesday","Wednesday","Thursday","Friday", "Saturday"};
const int ROWS=3, COLS=7;

// Class definitions
struct Statistics {

    Statistics(double amat[][COLS], int arows, int acols) {
        rows = arows;
        cols = acols;
        calc_statistics(amat, arows, acols);
    }
    private:
        int rows;
        int cols;
        // double mat[ROWS][COLS] = {};

    public:
        double total = 0;
        double average = 0;
        int minimum_row=0;
        int minimum_col=0;
        int maximum_row=0;
        int maximum_col=0;


    void calc_statistics(double mat[][COLS], int arows, int acols) {
        
        // Average & Calculate total
        average_food(mat);

        // Minimum
        minimum_food(mat);

        // Maximum
        maximum_food(mat);

    }

    void average_food(double mat[][COLS]) {
        double sum = 0;

        for (size_t i=0; i<rows; i++) {
            for (size_t j=0; j<cols; j++) {
                sum += mat[i][j];
            }
        }
        total = sum;
        average = (sum) / (cols);
    }

    void minimum_food(double mat[][COLS]) {
        auto minimum = mat[0][0];

        for (size_t i=0; i<rows; i++) {
            for (size_t j=0; j<cols; j++) {
                if (mat[i][j] < minimum) {
                    minimum = mat[i][j];
                    minimum_row = i;
                    minimum_col = j;
                }
            }
        }   
    }

    void maximum_food(double mat[][COLS]) {
        auto maximum = mat[0][0];

        for (size_t i=0; i < rows; i++) {
            for (size_t j=0; j < cols; j++) {
                if (mat[i][j] > maximum) {
                    maximum = mat[i][j];
                    maximum_row = i;
                    maximum_col = j;
                }
            }
        }   
    }

};

// Function declarations
template <typename T, std::size_t rows, std::size_t cols>
// typename T AverageArray[rows] // ???
// using myType = T[cols] // ???
T* average_food(T (&array)[rows][cols]) {
    /*Average the amount of food eaten per day by all monkeys
    Reduce sum on the 0th axis 
    row - monkey
    col - day*/
    T sum[cols] = {};
    static T average[cols] = {};
    auto size = rows * cols;

    std::cout << __func__ << std::endl;

    for (size_t i=0; i<rows; i++) {
        
        for (size_t j=0; j<cols; j++) {
            sum[j] += array[i][j];
        }

    }

    // Calculate average for each day
    for (size_t i=0; i<cols; i++) {
        average[i] = sum[i] / rows;
    }

    return average;
}


template <typename T, size_t rows, size_t cols>
T minimum_food(T (&array)[rows][cols]) {
    auto minimum = array[0][0];

    for (auto& row : array) {
        for (auto& val : row) { 
            if (val < minimum)
                minimum = val;
        }
    }

    return minimum;
}


template <typename T, size_t rows, size_t cols>
T maximum_food(T (&array)[rows][cols]) {
    auto maximum = array[0][0];

    for (auto& row : array) {
        for (auto& val : row) {
            if (val > maximum)
                maximum = val;
        }
    }

    return maximum;
}


template <typename T>
bool validate_input(T &val) {
    if (val < 0)
        return false;
    else
        return true;
    
    return false;
}


template <typename T, size_t rows, size_t cols>
void user_input(T (&array)[rows][cols]) {
    T val;

    for (int i=0; i < cols; i++) { // Weekdays

        for (int j=0; j < rows; j++) { // Monkeys
            std::cout << "Enter the food eaten by monkey #" << j + 1;
            std::cout << " on " << week_string[i] << ":";
            std::cin >> val;

            while (!validate_input(val)) {
                std::cout << "This input is not valid. Try again...";
                std::cout << "Enter the food eaten by monkey #" << j + 1;
                std::cout << " on " << week_string[i] << ":";
                std::cin >> val;
            }

            if (validate_input(val)) // Redundant check
                array[j][i] = val;
            else 
                throw std::invalid_argument("Invalid argument");
        }

    }

}


void report(Statistics statistics) {
 
    std::cout << "Average food consumed daily: " << statistics.average << endl;

    std::cout << "The least daily food consumed was by Monkey #" << statistics.minimum_row + 1;
    std::cout << " on " << week_string[statistics.minimum_col] << "." << endl;

    std::cout << "The most daily food consumed was by Monkey #" << statistics.maximum_row + 1;
    std::cout << " on " << week_string[statistics.maximum_col] << "." << endl;

}


int main () {
    // Initial Values
    double old_monkey_food[7][3] = {{8,4,6},
                                {4,4,6},
                                {4,4,6},
                                {4,4,6},
                                {4,4,6},
                                {3,3,5},
                                {2,4,5}};
    double monkey_food[3][7];
    for (int i=0; i<3; i++) {
        for (int j=0; j<7; j++) {
            monkey_food[i][j] = old_monkey_food[j][i];
        }
    }

    // Initialize array - for testing
    // std::default_random_engine generator;
    // std::uniform_real_distribution<double> distribution(1,100);
    // auto get_random = std::bind(distribution, generator );
    // for (auto& row : monkey_food) {
    //     for (auto& val : row) {
    //         val = get_random();
    //     }   
    // }

    // Read user input
    user_input(monkey_food);

    // Print report
    Statistics statistics(monkey_food, 3, 7);
    report(statistics);

    return 0;
}