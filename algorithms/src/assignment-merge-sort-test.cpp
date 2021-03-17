#include <vector>
#include <cassert>
#include <initializer_list>
#include <iostream>
#include <exception>
#include <algorithm>
#include <chrono>
#include <random>
#include <functional>
#include <tuple>
#include <map>
#include <set>

using namespace std;


template <typename T>
bool test_array_equal(T* arr1, int size1, T* arr2, int size2) {

    if (size1 != size2) {
        return false;
    }

    for (int i=0; i<size1; i++) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }

    return true;
}


template <typename T>
bool test_array_equal(T* arr1, int size1, std::initializer_list<T> l, int size2) {
    vector<T> arr2(l);

    if (size1 != size2) {
        return false;
    }

    for (int i=0; i<size1; i++) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }

    return true;
}


template <typename T>
string array_to_string(T* arr1, int size1) {
    string res;
    for (int i=0; i<size1; i++) {
        res += to_string(arr1[i]);
        res += (" ");
    }

    return res;
}


void test_merge_arrays() {
    std::cout << "Starting: " << __func__ << endl;

    {// a1 is inserted first
    int a1[5] {1,2,3,4,5};
    int a2[5] {10,11,12,13,14};
    int test[10] {1,2,3,4,5,10,11,12,13,14};
    auto res = merge_arrays(a1, 5, a2, 5);
    if (!test_array_equal(res, 10, test, 10) == true) {
        string msg = "Improper merge: ";
        msg += array_to_string(res, 10);
        msg += " Versus ";
        msg += array_to_string(test, 10);
        throw std::logic_error(msg);
    }
    else {
        string msg = "Successful merge: ";
        msg += array_to_string(a1, 5);
        msg += " Versus ";
        msg += array_to_string(a2, 5);
        msg += " results in: ";
        msg += array_to_string(test, 10);
        std::cout << msg << std::endl;
    }
    }

    {// a1 is inserted first, differnet size
    int a1[5] {1,2,3,4,5};
    int a2[6] {10,11,12,13,14,15};
    int test[11] {1,2,3,4,5,10,11,12,13,14,15};
    auto res = merge_arrays(a1, 5, a2, 6);
    if (!test_array_equal(res, 11, test, 11) == true) {
        string msg = "Improper merge: ";
        msg += array_to_string(res, 11);
        msg += " Versus ";
        msg += array_to_string(test, 11);
        throw std::logic_error(msg);
    }
    else {
        string msg = "Successful merge: ";
        msg += array_to_string(a1, 5);
        msg += " Versus ";
        msg += array_to_string(a2, 6);
        msg += " results in: ";
        msg += array_to_string(test, 11);
        std::cout << msg << std::endl;
    }
    }

    {// a2 is inserted first
    int a1[3] {1,2,3};
    int a2[3] {-2,-1,0};
    int test[6] {-2,-1,0,1,2,3};
    auto res = merge_arrays(a1, 3, a2, 3);
    if (!test_array_equal(res, 6, test, 6) == true) {
        string msg = "Improper merge: ";
        msg += array_to_string(res, 6);
        msg += " Versus ";
        msg += array_to_string(test, 6);
        throw std::logic_error(msg);
    }
    else {
        string msg = "Successful merge: ";
        msg += array_to_string(a1, 3);
        msg += " Versus ";
        msg += array_to_string(a2, 3);
        msg += " results in: ";
        msg += array_to_string(test, 6);
        std::cout << msg << std::endl;
    }
    }

    {// a2 is inserted first, different size
    int a1[3] {2,2,3};
    int a2[4] {-2,-1,0,1};
    int test[7] {-2,-1,0,1,2,2,3};
    auto res = merge_arrays(a1, 3, a2, 4);
    if (!test_array_equal(res, 7, test, 7) == true) {
        string msg = "Improper merge: ";
        msg += array_to_string(res, 7);
        msg += " Versus ";
        msg += array_to_string(test, 7);
        throw std::logic_error(msg);
    }
    else {
        string msg = "Successful merge: ";
        msg += array_to_string(a1, 3);
        msg += " Versus ";
        msg += array_to_string(a2, 4);
        msg += " results in: ";
        msg += array_to_string(test, 7);
        std::cout << msg << std::endl;
    }
    }
    
    {// Mixed arrays
    int a1[4] {0,1,3,5};
    int a2[4] {2,4,6,9};
    int test[8] {0,1,2,3,4,5,6,9};
    auto res = merge_arrays(a1, 4, a2, 4);
    if (!test_array_equal(res, 8, test, 8) == true) {
        string msg = "Improper merge: ";
        msg += array_to_string(res, 8);
        msg += " Versus ";
        msg += array_to_string(test, 8);
        throw std::logic_error(msg);
    }
    else {
        string msg = "Successful merge: ";
        msg += array_to_string(a1, 4);
        msg += " Versus ";
        msg += array_to_string(a2, 4);
        msg += " results in: ";
        msg += array_to_string(test, 8);
        std::cout << msg << std::endl;
    }
    }

    {// a1 empty
    int a1[] {};
    int a2[4] {2,4,6,9};
    int test[4] {2,4,6,9};
    auto res = merge_arrays(a1, 0, a2, 4);
    if (!test_array_equal(res, 4, test, 4) == true) {
        string msg = "Improper merge: ";
        msg += array_to_string(res, 4);
        msg += " Versus ";
        msg += array_to_string(test, 4);
        throw std::logic_error(msg);
    }
    else {
        string msg = "Successful merge: ";
        msg += array_to_string(a1, 0);
        msg += " Versus ";
        msg += array_to_string(a2, 4);
        msg += " results in: ";
        msg += array_to_string(test, 4);
        std::cout << msg << std::endl;
    }
    }

    {// a2 empty
    int a1[4] {2,4,6,9};
    int a2[0] {};
    int test[4] {2,4,6,9};
    auto res = merge_arrays(a1, 4, a2, 0);
    if (!test_array_equal(res, 4, test, 4) == true) {
        string msg = "Improper merge: ";
        msg += array_to_string(res, 4);
        msg += " Versus ";
        msg += array_to_string(test, 4);
        throw std::logic_error(msg);
    }
    else {
        string msg = "Successful merge: ";
        msg += array_to_string(a1, 4);
        msg += " Versus ";
        msg += array_to_string(a2, 0);
        msg += " results in: ";
        msg += array_to_string(test, 4);
        std::cout << msg << std::endl;
    }
    }

    {// both empty
    int a1[0] {};
    int a2[0] {};
    int test[0] {};
    auto res = merge_arrays(a1, 4, a2, 0);
    if (!test_array_equal(res, 0, test, 0) == true) {
        string msg = "Improper merge: ";
        msg += array_to_string(res, 0);
        msg += " Versus ";
        msg += array_to_string(test, 0);
        throw std::logic_error(msg);
    }
    else {
        string msg = "Successful merge: ";
        msg += array_to_string(a1, 0);
        msg += " Versus ";
        msg += array_to_string(a2, 0);
        msg += " results in: ";
        msg += array_to_string(test, 0);
        std::cout << msg << std::endl;
    }
    }

    std::cout << "SUCCESS: " << __func__ << endl;
}


void test_merge_arrays_execution_time() {

    // Measure execution time - visualize linearity
    int n=20; // Number of times we measure each function call
    vector<std::tuple<double, int>> durations;
    // std::chrono::nanoseconds duration;
    std::chrono::duration<double> duration;
    std::chrono::_V2::system_clock::time_point start, stop;

    // Generate some data

    vector<vector<double>> data {vector<double>(1e3), vector<double>(1e4), vector<double>(1e5), vector<double>(1e6), vector<double>(1e7), vector<double>(1e8)};

    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(0.0, 1.0);
    auto roll_dice = std::bind(distribution, generator);

    for (auto& vec : data) {
        for (int i=0; i<vec.size(); i++) {
            vec[i] = roll_dice();
        }
        std::sort(vec.begin(), vec.end()); // Sort the vector for merging..
    }

    for (auto& vec : data) {
        // Split vector into two
        std::vector<double> v1(vec.size() / 2), v2(vec.size() / 2);
        std::copy(vec.begin(), (vec.begin() + vec.size() / 2) - 1, v1.begin());
        std::copy((vec.begin() + vec.size() / 2), vec.end(), v2.begin());

        for (int i=0; i<n; i++) {

            // Measure time
            start = std::chrono::high_resolution_clock::now();

            // Call function
            auto res = merge_arrays(v1.data(), v1.size(), v2.data(), v2.size());

            // Measure time
            stop = std::chrono::high_resolution_clock::now();
            duration = (stop-start);
            durations.push_back(std::make_tuple(duration.count(), vec.size() / 2));
            delete[] res; // Bad program design
        }
    }

    // Average the duration of each size
    std::map<int, double> avg_duration;
    std::map<int, std::vector<double>> duration_map;
    // Get unique keys
    std::set<int> keys;
    for (auto& [key, val] : durations) {
        keys.insert(val); // Insert size of vector
    }

    for (auto& key : keys) {
        duration_map.insert({key, std::vector<double>{}});
    }

    // Accumulate values
    for (auto& [val, key] : durations) {
        duration_map[key].push_back(val);
    }

    // Calculation averages
    for (auto& [key, val] : duration_map) {
        auto sum = std::accumulate(val.begin(), val.end(), 0.0);
        auto n = val.size();
        std::cout << "With " << key << " array elements the average execution time was " << sum / n << "\n\n";
    }
}


template <typename T>
void print_array(T* arr1, int size1) {
    for (int i=0; i<size1; i++) {
        std::cout << arr1[i] << " ";
    }
}
