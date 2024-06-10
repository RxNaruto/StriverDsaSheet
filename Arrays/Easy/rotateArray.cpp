#include<iostream>
using namespace std;
void rotateArray(int arr[],int size){
    int temp=arr[size-1];
    for(int i=size-1;i>0;i--){
        arr[i]=arr[i-1];

    }
    arr[0]=temp;
}
int main()
{
    int arr[5]={1,2,3,4,5};
    rotateArray(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
 return 0;
}