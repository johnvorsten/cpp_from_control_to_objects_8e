#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>

using namespace std;


static bool abs_compare(int a, int b)
{
    return (std::abs(a) < std::abs(b));
}

template <typename T, size_t rows, size_t cols>
void Statistics(double amat[rows][cols], int arows, int acols) {
    auto mat = amat;
    auto rows = arows;
    auto cols = acols;
}

void test() {

    double monkey_food[3][7] = {};
    Statistics(monkey_food, 3, 7);
}



int main()
{
    std::vector<int> v{ 3, 1, -14, 1, 5, 9 }; 
    std::vector<double> v2{1.357, 2.0, 3.0, 100.0};
    // std::vector<int>::iterator result;
 
    auto result = std::max_element(v.begin(), v.end());
    std::cout << "max element at: " << std::distance(v.begin(), result) << '\n';
 
    std::vector<int>::iterator result2;
    result2 = std::max_element(v.begin(), v.end(), abs_compare);
    std::cout << "max element (absolute) at: " << std::distance(v.begin(), result2) << '\n';

    auto accum = std::accumulate(v.begin(), v.end(), 0);
    auto accum2 = std::accumulate(v2.begin(), v2.end(), 0.0);

    // Testing 2d arrays
    int rows = 3;
    int cols = 4;
    double mat[3][4] = {{1.357, 2.0, 3.0, 100.0}, 
                        {1, 2, 3, 4}, 
                        {5, 6, 7, 8}};
    double total = 0;
    double average = 0;
    // std::vector<double>::iterator minimum;
    // std::vector<double>::iterator maximum;
    // double** minimum;
    // double** maximum;
    std::vector<double>::difference_type minimum_month;
    std::vector<double>::difference_type maximum_month;

    // Calculate total
    total = std::accumulate(mat, mat + (rows * cols), 0.0);

    // Average
    average = std::accumulate(mat, mat + (rows * cols), 0.0) / (rows * cols);

    // minimum
    auto minimum = std::min_element(mat, mat + (rows * cols));
    auto minimum_row = (minimum - mat) % rows;
    auto minimum_day = (minimum - mat) % cols;



}