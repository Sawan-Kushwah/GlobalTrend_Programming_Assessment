// Q6 Write a function to find the factorial of a given number.The function should return the factorial of the number.
#include <iostream>
using namespace std;
long factorial(int n)
{
    long fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
    }
    return fact;
}
int main()
{
    int n = 7;
    cout << "Factorial of " << n << " is " << factorial(n) << endl;
    return 0;
}
