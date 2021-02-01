#include <iostream>
#include <vector>
#include <string>
#include <map>
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

    Statistics(vector<double> avec, std::map<std::string, double> amap) {
        vec = avec;
        mmap = amap;
        calc_statistics(avec);
    }

    public:
        vector<double> vec;
        std::map<std::string, double> mmap;
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

struct user_input_s {
    public:
        vector<double> rainfall_array;
        std::map<std::string, double> rainfall_map;
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


user_input_s user_input() {
    vector<double> array(12);
    double res;
    std::map<std::string, double> rainfall_map;

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
        rainfall_map[month_str[i]] = res;
    }

    user_input_s output;
    output.rainfall_array = array;
    output.rainfall_map = rainfall_map;

    return output;
}

template <typename T1, typename T2>
struct less_second {
    typedef pair<T1, T2> type;
    bool operator ()(type const& a, type const& b) const {
        return a.second < b.second;
    }
};


void report(Statistics statistics) {
 
    std::cout << "Total rainfall: " << statistics.total << endl;
    std::cout << "Average rainfall: " << statistics.average << endl;
    std::cout << "Least rainfall in: " << month_str[statistics.minimum_month] << endl;
    std::cout << "Most rainfall in: " << month_str[statistics.maximum_month] << endl;

    // Print all rainfall amounts
    vector<pair<string, double>> mapcopy(statistics.mmap.begin(), statistics.mmap.end());
    std::sort(mapcopy.begin(), mapcopy.end(), less_second<string, double>());
    for (const auto& [month, rainfall] : mapcopy) {
        std::cout << rainfall << " inches in " << month << endl;
    }
}



int main () {

    auto rainfall = user_input();
    // vector<double> rainfall{1,2,3,4,5,6,7,8,9,10,11,12};
    auto statistics = Statistics(rainfall.rainfall_array, rainfall.rainfall_map);
    report(statistics);

    return 0;
}