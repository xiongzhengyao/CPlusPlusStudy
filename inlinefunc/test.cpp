#include <stdio.h>
#include <iostream>

#define  SQUARE(X) ((X)*(X))

inline double square(double x) { return x*x; }


int main(void)
{
    using namespace std;
    double result,result1;
    double a = 2.0;
    double c = 3.0;

    result = square(a++);
    cout << "result is:" << result << endl;

    result1 = SQUARE(c++);
    cout << "result1 is:" << result1 << endl;
}