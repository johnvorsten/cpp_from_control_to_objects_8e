#include <iostream>

using namespace std;

// Global constants
const int N_COLS = 4;

void display_array(char array[][N_COLS], int n_rows) {
    for (int row=0; row < n_rows; row++) {
        for (int col=0; col < N_COLS; col++) {
            std::cout << array[row][col] << " ";
        }
        std::cout << endl;
    }
}

int main () {
    // 2d array
    const int d1 = 5;
    const int d2 = 10;
    char array1[d1][d2];
    char array2[d1][d2] {{'a','b'},{'c','d'}};


    // Passing to functions
    const int N_COLS = 4;
    const int N_ROWS = 3;
    char array3[N_ROWS][N_COLS];
    display_array(array3, N_ROWS);

    return 0;
}