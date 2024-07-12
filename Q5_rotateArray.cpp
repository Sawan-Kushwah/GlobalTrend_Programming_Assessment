// Q5 Write a function to rotate an array to the right by k steps.The function should modify the array in place to achieve the rotation


#include <iostream>
using namespace std;
void reverseArray(int arr[] , int s , int e){
    int start = s;
    int end = e;
    while(start <= end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void rotateArray(int arr[] , int n , int k){
    int effectiveRotation = k % n;
    reverseArray(arr,0 , n - effectiveRotation);
    reverseArray(arr , n - effectiveRotation + 1 , n);
    reverseArray(arr, 0 , n);
}

int main()
{
    // Output
    // Before K rotation
    // 1 2 3 4 5 6
    // After K rotation
    // 5 6 1 2 3 4

    int arr[] = {1,2,3,4,5,6};
    int length = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    cout<<"Before K rotation"<<endl;
    for(int i = 0; i < length; i++){
        cout<<arr[i]<<" ";
    }

    rotateArray(arr ,length-1, k);

    cout<<"\nAfter K rotation"<<endl;
    for(int i = 0; i < length; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
