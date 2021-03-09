/*Write a  function that merges two sorted array-based lists 
into one sorted array-based list.  The function takes two arrays 
as parameters, each holding a sorted list of integers, merges 
them into  a single sorted list, and returns the result.  Note 
that this function performs the merge part of the merge sort algorithm.

The function should have a linear time complexity i.e. O(N), 
where N is the sum of the length of the two input lists it 
merges. Note: functions that are not linear will not get any credit.

Deliverables:

A copy of your merge function code in a text file.
A copy of a test program to test your function. Be sure to 
    test all cases e.g. two empty lists, one empty only, 
    lists with 1 element each, lists with multiple elements.
Screenshots of your test runs showing your function meets specifications.
*/

#include <vector>
// #include "./algorithms/matplotlib-cpp-master/matplotlibcpp.h"
#include "matplotlibcpp.h"

using namespace std;
namespace plt = matplotlibcpp;


template <typename T>
vector<T> merge(T* arr1, T* arr2) {

}


int main () {

    {
    // Simple example
    plt::plot({1,3,2,4});
    plt::show();
    }

    {
    // Complex example
    // Prepare data.
    int n = 5000;
    std::vector<double> x(n), y(n), z(n), w(n,2);
    for(int i=0; i<n; ++i) {
        x.at(i) = i*i;
        y.at(i) = sin(2*M_PI*i/360.0);
        z.at(i) = log(i);
    }

    // Set the size of output image to 1200x780 pixels
    plt::figure_size(1200, 780);
    // Plot line from given x and y data. Color is selected automatically.
    plt::plot(x, y);
    // Plot a red dashed line from given x and y data.
    plt::plot(x, w,"r--");
    // Plot a line whose name will show up as "log(x)" in the legend.
    plt::named_plot("log(x)", x, z);
    // Set x-axis to interval [0,1000000]
    plt::xlim(0, 1000*1000);
    // Add graph title
    plt::title("Sample figure");
    // Enable legend.
    plt::legend();
    // Save the image (file format is determined by the extension)
    plt::save("./basic.png");
    }



    {
    // Prepare data.
    int n = 5000; // number of data points
    vector<double> x(n),y(n);
    for(int i=0; i<n; ++i) {
        double t = 2*M_PI*i/n;
        x.at(i) = 16*sin(t)*sin(t)*sin(t);
        y.at(i) = 13*cos(t) - 5*cos(2*t) - 2*cos(3*t) - cos(4*t);
    }

    // plot() takes an arbitrary number of (x,y,format)-triples.
    // x must be iterable (that is, anything providing begin(x) and end(x)),
    // y must either be callable (providing operator() const) or iterable.
    plt::plot(x, y, "r-", x, [](double d) { return 12.5+abs(sin(d)); }, "k-");


    // show plots
    plt::show();
    }

    return 0;
}