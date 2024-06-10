#include<iostream>
using namespace std;

void rotateLeft(int arr[],int size,int k){
        int temp=arr[k];
    for(int i=k;i<size-1;i++){
        arr[i]=arr[i+1];
        
    }
    arr[size-1]=temp;

}

void moveZerosToEnd(int arr[],int size){
    
    for(int i=0;i<size;i++){
        if(arr[i]==0){
          rotateLeft(arr,size,i);
          
        }
    }
}
int main()
{
    int arr[7]={1,2,0,1,0,4,0};
    moveZerosToEnd(arr,7);
    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }
 return 0;
}