// Q7 Write a function to compute the sum of the digits of a given number.The function should return the sum of the digits of the number.

#include <iostream>
using namespace std;
int sumOfDigit(int n){
    int sum=0;
    while(n > 0){
        sum = sum + n % 10;
        n = n / 10;
    }
    return sum;
}
int main()
{
    int n = 18345; // 1 + 8 + 3 + 4 + 5 = 21
    cout << "Sum of digit of " << n << " is " << sumOfDigit(n) << endl;
    return 0;
}
