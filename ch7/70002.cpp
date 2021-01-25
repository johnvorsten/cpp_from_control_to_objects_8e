#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>

using namespace std;

// Data declarations
enum months {January, February, March, April, May, June, 
July, August, September, October, November, December};
vector<string> month_str = {"January", "February", 
        "March", "April", 
        "May", "June", 
        "July", "August", 
        "September", "October", 
        "November", "December"};


struct Statistics {

    Statistics(vector<double> avec) {
        vec = avec;
        calc_statistics(avec);
    }

    public:
        vector<double> vec;
        double total = 0;
        double average = 0;
        std::vector<double>::iterator minimum;
        std::vector<double>::iterator maximum;
        std::vector<double>::difference_type minimum_month;
        std::vector<double>::difference_type maximum_month;

    void calc_statistics(vector<double> vec) {
        // Calculate total
        total = std::accumulate(vec.begin(), vec.end(), 0.0);

        // Average
        average = std::accumulate(vec.begin(), vec.end(), 0.0) / vec.size();

        // minimum
        minimum = std::min_element(vec.begin(), vec.end());
        minimum_month = std::distance(vec.begin(), minimum);

        // Maximum 
        maximum = std::max_element(vec.begin(), vec.end());
        maximum_month = std::distance(vec.begin(), maximum);

    }

};


// Function declarations
template <typename T>
bool validate_input(T input) {
    bool res = false;

    if (input < 0)
        res = false;
    else
        res = true;
    return res;
}


vector<double> user_input() {
    vector<double> array(12);
    double res;

    for (int i=0; i < array.size(); i++) {
        std::cout << "Enter rainfall for " << month_str[i] << ": ";
        std::cin >> res;
        while (!validate_input(res)) {
            std::cout << "You entered a negative number" << endl;
            std::cout << "Enter rainfall for " << month_str[i] << ": ";
            std::cin >> res;
        }
        // std::cout << endl;
        array[i] = res;
    }

    return array;
}


void report(Statistics statistics) {
 
    std::cout << "Total rainfall: " << statistics.total << endl;
    std::cout << "Average rainfall: " << statistics.average << endl;
    std::cout << "Least rainfall in: " << month_str[statistics.minimum_month] << endl;
    std::cout << "Most rainfall in: " << month_str[statistics.maximum_month] << endl;

}


int main () {

    auto rainfall = user_input();
    // vector<double> rainfall{1,2,3,4,5,6,7,8,9,10,11,12};
    auto statistics = Statistics(rainfall);
    report(statistics);

    return 0;
}