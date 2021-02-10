#include <iostream>

int mystery(int list[], int first, int last) {
    if (first == last) {
        return list[first];
    }
    else
    {
        return list[first] + mystery(list, first + 1, last);
    }
    
}


int main () {

    int beta[10] = {2,5,8,9,13,15,18,20,23,25};

    std::cout << mystery(beta, 4,7);

    return 0;
}