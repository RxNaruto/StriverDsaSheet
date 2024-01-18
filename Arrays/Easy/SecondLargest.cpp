#include<iostream>
using namespace std;
int secondLargest(int arr[],int size){
    int secondLargest=arr[0];
    int largest=arr[0];
    for(int i=1;i<size;i++){
        if(arr[i]>largest){
            secondLargest=largest;
            largest=arr[i];
        }
    }
    return secondLargest;
}
int main()
{
    int arr[5]={1,231,34,422,5};
    cout<<"The second largest element is "<<secondLargest(arr,5);
 return 0;
}