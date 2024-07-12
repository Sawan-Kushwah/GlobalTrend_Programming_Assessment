// Q8 Write a function to find the greatest common divisor (GCD) of two numbers. The function should return the GCD of a and b.
#include <iostream>
using namespace std;
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int main()
{
    int a = 10;
    int b = 15;
    cout << "GCD of " << a << " and " << b << " is " << gcd(a, b) << endl;
    return 0;
}
