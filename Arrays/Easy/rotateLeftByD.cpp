#include<iostream>
using namespace std;
void rotateLeftByD(int arr[],int size,int d){
    for(int i=0;i<d;i++){
        int temp=arr[0];
    for(int i=0;i<size-1;i++){
        arr[i]=arr[i+1];
        
    }
    arr[size-1]=temp;
    }
}
int main()
{
    int arr[5]={1,2,3,4,5};
    rotateLeftByD(arr,5,2);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
 return 0;
}