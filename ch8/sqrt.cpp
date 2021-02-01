#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

bool isSorted(int* arr, int size, bool a) {
	
	bool res = true;
	
	if (a) {
		for (int i=1; i<size; i++) {
			if (arr[i-1] > arr[i]) {
				res = false;
			}
		}
	}
	else {
		for (int i=1; i<size; i++) {
			if (arr[i-1] < arr[i]) {
				res = false;
			}
		}
	}
	
	return res;
}


void print_some() {

    int n=0;
    bool wasReadIn[50] = {false};

    int val = 0;
    // std::cin >> n;

    for (int i=0; i<50; i++) {
        wasReadIn[i] = false;
    }

    for (int i=0; i<n; i++) {
        std::cin >> val;
        wasReadIn[val] = true;
    }

    for (int i=0; i<50; i++) {
        if (wasReadIn[i])
            std::cout << i << " ";
    }

}


void print_some2() {

    int n=9;
    int wasReadIn[n] = {0};
    int val = 0;
    std::cin >> n;

    for (int i=0; i<n; i++) {
        wasReadIn[i] = 0;
    }

    for (int i=0; i<n; i++) {
        std::cin >> val;
        wasReadIn[val] += 1;
    }

    for (int i=0; i<n; i++) {
        while (wasReadIn[i] > 0) {
            std::cout << i << " ";
            wasReadIn[i] -= 1;
        }
    }


}




int main () {

    {
    double x = 10;
    double root = 0;
    double a=1, b=x;
    auto midpoint = ((b-a) / 2 + a);

    // Find the square root of x
    for (int i=0; i<1000; i++) {
        midpoint = ((b - a) / 2) + a;
        if ((midpoint * midpoint) > x) {
            // The midpoint is not the square root - too high
            b = midpoint;
        }
        else {
            a = midpoint;
        }
    }
    root = midpoint;

    std::cout << "Estimated square root : " << root << endl;
    std::cout << "Actual square root : " << sqrt(x) << endl;
    }

    // {
    // print_some();
    // }

    // {
    // print_some2();
    // }

    {
    // Already declared
    // vector<string> x = {"e","a","c","d","a"};
    string x[5] = {"e","a","c","d","a"};
    int n = 5;
    string mode;

    // Mine
    #include <algorithm>
    std::sort (x, x + n);
    int counter = 1;
    int max = 0;

    for (int pass = 0; pass < n - 1; pass++) {
           if ( x[pass] == x[pass+1] )
           {
              counter++;
              if ( counter > max )
              {
                  max = counter;
                  mode = x[pass];
              }
           } else
              counter = 1; // reset counter.
    }

    }

    return 0;
}