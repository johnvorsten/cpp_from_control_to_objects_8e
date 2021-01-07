#include <iostream>
#include <stdio.h>
#include <math.h>
#include <typeinfo>
#include <type_traits>

using namespace std;

// Function prototype / declarations
double return_double(int x, int y){
    double res;
    res = x + y; // x and y are automatically promoted to double??
    return res;
}

double return_double(int x, float y){
    double res;
    res = x + y; // x and y are automatically promoted to double??
    return res;
}

double return_double(float x, int y){
    double res;
    res = x + y; // x and y are automatically promoted to double??
    return res;
}

double return_double(float x, float y){
    double res;
    res = x + y; // x and y are automatically promoted to double??
    return res;
}


int main () {
    // Initial values
    int a1=1, b1=2;
    float a2=1, b2=2;
    double a3=1, b3=2;

    // Return data types
    int res1;
    float res2;
    double res3;
    bool typebool;
    // std::cout << std::boolalpha;
    // typebool = std::is_same<int, decltype(res1)>{}(); // Instantiate and use operator()
    // typebool = std::is_same<int, decltype(res1)>::value; // Use static member
    // std::cout << "res1 is int : " << typebool << '\n';

    /*Program goal - 
    How is a variable promoted or demoted based on the function return type
    and variable data type?
    Case
        Return double, store int
        Return double, store float
        Return double, store double
    
    Goal 2 - How is a variable promosted / demoted based on the variable
    it is stored in?
    Case
        Variable type is double, operate on int, int
        Variable type is double, operate on int, float
        Variable type is double, operate on float, int
        Variable type is double, operate on float, float
    */
    std::cout << std::boolalpha;

    // Case - Function call int, int
    res1 = return_double(a1,b1);
    res2 = return_double(a1,b1);
    res3 = return_double(a1,b1);
    printf("res1 type: %s\n", typeid(res1).name());
    printf("res2 type: %s\n", typeid(res2).name());
    printf("res3 type: %s\n", typeid(res3).name());
    printf("res1 is int %s\n", std::is_same<int, decltype(res1)>{}() ? "true" : "false");
    printf("res2 is float %s\n", std::is_same<float, decltype(res2)>{}() ? "true" : "false");
    printf("res3 is double %s\n", std::is_same<double, decltype(res3)>{}() ? "true" : "false");
    printf("Integer result %-+5.2i\n", res1);
    printf("Float result %-+5.2f\n", res2);
    printf("Double result %-+5.2f\n", res3);

    // Case - Function call int, float
    res1 = return_double(a1,b2);
    res2 = return_double(a1,b2);
    res3 = return_double(a1,b2);
    printf("res1 type: %s\n", typeid(res1).name());
    printf("res2 type: %s\n", typeid(res2).name());
    printf("res3 type: %s\n", typeid(res3).name());
    printf("res1 is int %s\n", std::is_same<int, decltype(res1)>{}() ? "true" : "false");
    printf("res2 is float %s\n", std::is_same<float, decltype(res2)>{}() ? "true" : "false");
    printf("res3 is double %s\n", std::is_same<double, decltype(res3)>{}() ? "true" : "false");
    printf("Integer result %-+5.2i\n", res1);
    printf("Float result %-+5.2f\n", res2);
    printf("Double result %-+5.2f\n", res3);

    // Case - Function call float, int
    res1 = return_double(a2,b1);
    res2 = return_double(a2,b1);
    res3 = return_double(a2,b1);
    printf("res1 type: %s\n", typeid(res1).name());
    printf("res2 type: %s\n", typeid(res2).name());
    printf("res3 type: %s\n", typeid(res3).name());
    printf("res1 is int %s\n", std::is_same<int, decltype(res1)>{}() ? "true" : "false");
    printf("res2 is float %s\n", std::is_same<float, decltype(res2)>{}() ? "true" : "false");
    printf("res3 is double %s\n", std::is_same<double, decltype(res3)>{}() ? "true" : "false");
    printf("Integer result %-+5.2i\n", res1);
    printf("Float result %-+5.2f\n", res2);
    printf("Double result %-+5.2f\n", res3);

    // Case - Function call float, float
    res1 = return_double(a2,b2);
    res2 = return_double(a2,b2);
    res3 = return_double(a2,b2);
    printf("res1 type: %s\n", typeid(res1).name());
    printf("res2 type: %s\n", typeid(res2).name());
    printf("res3 type: %s\n", typeid(res3).name());
    printf("res1 is int %s\n", std::is_same<int, decltype(res1)>{}() ? "true" : "false");
    printf("res2 is float %s\n", std::is_same<float, decltype(res2)>{}() ? "true" : "false");
    printf("res3 is double %s\n", std::is_same<double, decltype(res3)>{}() ? "true" : "false");
    printf("Integer result %-+5.2i\n", res1);
    printf("Float result %-+5.2f\n", res2);
    printf("Double result %-+5.2f\n", res3);

    return 0;
}