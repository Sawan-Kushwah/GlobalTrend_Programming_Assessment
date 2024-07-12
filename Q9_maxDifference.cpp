// Q9 Write a function to find the maximum difference between any two elements in an array.The function should return the maximum difference between any two elements in the array.

#include <iostream>
using namespace std;
int maximumDifference(int arr[], int n)
{
    if (n < 2)
        return 0;

    int maxi = arr[0];
    int mini = arr[0];

    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
        mini = min(mini, arr[i]);
    }
    return maxi - mini;
}
int main()
{
    int arr[] = {2, 1, 4, 6, 9};
    int length = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum Difference is " << maximumDifference(arr, length) << endl;
    return 0;
}
