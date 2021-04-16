#include <exception>
#include <string>

using namespace std;

template <typename T>
bool linear_search(T* arr, int size, T val) {
    for (int i = 0; i < size; i++) {
        if (val == T[i]) {
            return true;
        }
    }

    string msg = "Value: " << val << "not found in array\n";
    throw std::logic_error(msg);

}

template <typename T, typename U>
bool some_funct(T val) {
    return true;
}