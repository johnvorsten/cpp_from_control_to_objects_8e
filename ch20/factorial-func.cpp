#include <iostream>
#include <cmath>
#include <string>

namespace recursive {

template <typename T>
T factorial(const T& arg) {
    /*Return the factorial of function argument*/
    if (arg == 0 || arg == 1) {
        return 1;
    }

    return arg * factorial(arg - 1);
}

template <typename T>
T power(const T& arg, unsigned int exponent) {
    /*Return the power of argument to the power of 'exponent'*/
    T temp;
    
    if (exponent == 0) {
        return 1;
    }
    else if (exponent == 1) {
        return arg;
    }

    return arg * power(arg, exponent - 1);
}

int search_string(const std::string& str, int start) {

    return true;
}

}; // End of recursive namespace

using namespace recursive;

bool equals(int a, int b) {

	if (a == 0 && b == 0 || equals(a-1, b-1)) {
		return true;
	}
	// else if (equals(a-1, b-1)) {
	// 	return true;
	// }
		
	return false;
}


bool containsVowel(std::string a) {
    char test;
	for (auto& ch : a) {
        test = tolower(ch);
		if (test == 'a' || test == 'e' || test == 'i' || test == 'o' || test == 'u' || test == 'y') {
			return true;
		}
	}
    return false;
}

std::string replace(std::string str) {
    char test = ' ';

	if (str.length() == 0) {
		return str;
	}
	if (!(str[0] == test)) {
		return str[0] + replace(str.substr(1, std::string::npos));
	}
	else {
		return "*" + replace(str.substr(1, std::string::npos));
	}
	
}

std::string reverse(std::string str) {
	if (str.length() == 0) {
		return str;
	}
	
	return str.back() + reverse(str.substr(0, str.length() - 1));
}

int* clear(int* arr, int size) {

    if (size == 0) {
        return arr;
    }
    else {
        arr[size - 1] = 0;
    }

    clear(arr, size - 1);
}

int sum(int* arr, int size) {
    if (size == 0) {
        return 0;
    }

    return arr[size - 1] + sum(arr, size-1);
}

bool isPalindrome(int* arr, int size) {
    
    if (size == 0 || size == 1) {
        return true;
    }

    else if (size == 2 && arr[0] == arr[1]) {
        return true;
    }

    else if (arr[0] == arr[size - 1]) {
        return isPalindrome(arr + 1, size - 2);
    }

    return false;
}

int max(int* arr, int size) {
    if (size == 1) {
        return arr[0];
    }

    else if (size < 1) {
        return 0;
    }

    else if (arr[0] > max(arr + 1, size - 1)) {
        return arr[0];
    }
    
    return max(arr + 1, size - 1);
}

void init(int* arr, int size) {
    if (size == 0) {
        return;
    }
    else {
        arr[size - 1] = size - 1;
    }

    init(arr, size - 1);
}

int productOfOdds(int* arr, int size) {
    // Product of odd value elements in array
    if (size == 1 && !(arr[0] % 2 == 0)) {
        return arr[0];
    }

    if (!(arr[0] % 2 == 0)) {
        return arr[0] * productOfOdds(arr + 1, size - 1);
    }

    else {
        return productOfOdds(arr + 1, size - 1);
    }

    return 1;
}


double harmonic(int n) {
	
	if (n == 1) {
		return 1.0;
	}
	
	return (1.0 / n) + harmonic(n - 1);
	
}

template <typename T>
long oddevenfact(T arg) {

    if (arg == 0) {
        return 1;
    }
    else if (arg == 1) {
        return 1;
    }
    else if (arg == 2) {
        return 2;
    }

    return arg * oddevenfact(arg - 2);
}

void printTriangle(int start, int stop) {

    if (start > stop) {
        return;
    }

    std::string res(start, '*');
    std::cout << res << "\n";
    printTriangle(start + 1, stop);

}

void printTriangle(int start) {
    printTriangle(1, start);
}

void printStarBucks(int n) {

    if (n == 0) {
        return;
    }

    std::string res(n, '*');
    std::cout << res;
    res.clear();
    res.assign(n, '$');
    std::cout << res;

}

#include <cmath>

void printPowerOfTwoStars(int n) {
    std::string str;
    str.assign(static_cast<int>(pow(2, n)), '*');
    std::cout << str;
}


void copy() {
    std::string str;
    if (std::cin >> str) {
        std::cout << str << "\n";
        copy();
    }
    else {
        return;
    }

}


void rcopy() {
    std::string str;
    if (std::cin >> str) {
        
        rcopy();
    }
    else {
        return;
    }
    std::cout << str << "\n";
}

int add() {
    int val = 0;
    if (std::cin >> val) {
    }
    else {
        return 0;
    }

    return val + add();
}

int count() {
    int cnt = 0;
    std::string str;
    if (std::cin >> str) {
        cnt += 1;
    }
    else {
        return cnt;
    }

    return cnt + count();
}

int countPos() {
    int in = 0;
    int count = 0;

    if (std::cin >> in) {
        if (in > 0) {
            count ++;
        }
    }
    else {
        return 0;
    }

    return count + countPos();
}


int main () {

    auto res = harmonic(10);
    printTriangle(5);

    return 0;
}

