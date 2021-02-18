#include <iostream>
#include <cmath>

using namespace std;

struct point {
    double x;
    double y;
};

int main () {

    point p1 {1,2};
    point p2 {2,3};

    auto res = pow(pow((p1.x - p2.x),2) + pow((p1.y - p2.y), 2), 1/2);

    return 0;
}b