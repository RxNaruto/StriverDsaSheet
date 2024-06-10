#include<iostream>
using namespace std;
int secondLargest(int arr[],int size){
    int firstLargest=arr[0];
    int secondLargest=arr[0];
    for(int i=1;i<size;i++){
        if(arr[i]>firstLargest){
            secondLargest=firstLargest;
            firstLargest=arr[i];
        }
        else if(arr[i]>secondLargest){
            secondLargest=arr[i];
        }
    }
    return secondLargest;
}
int main()
{
    int arr[5]={1,5,3,65,6};
    cout<<"The second largest element in an array is "<<secondLargest(arr,5);
 return 0;
}