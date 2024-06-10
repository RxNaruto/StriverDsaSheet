#include<iostream>
using namespace std;
int largestElement(int arr[],int size){
    int max=arr[0];
    for(int i=1;i<size;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}
int main()
{
    int arr[5]={1,6,3,22,8};
    cout<<"The largest element in an array is "<<largestElement(arr,5);
 return 0;
}