#include<iostream>
using namespace std;
int LargestElement(int arr[],int size){
    int largest=arr[0];
    for(int i=1;i<size;i++){
        if(arr[i]>largest){
            largest=arr[i];
        }
        
    }
    return largest;
}
int main()
{
    int arr[5]={1,2,30,4,5};
    cout<<"The largest Element in array is "<<LargestElement(arr,5);
 return 0;
}