#include<iostream>
using namespace std;

void overlap(int arr[],int k,int size){
    for(int i=k;i<size;i++){
        arr[i]=arr[i+1];
    }
    arr[size-1]=0;
}

void removeDuplicates(int arr[],int size){
    
    for(int i=1;i<size;i++){
        if(arr[i]==arr[i-1]){
            overlap(arr,i,size);
             size--;
             i--;
          
        }
        
    }
}
int main()
{
    int arr[11]={1,1,1,2,2,3,3,3,3,4,4};
    removeDuplicates(arr,11);
    for(int i=0;i<11;i++){
        cout<<arr[i]<<" ";
    }
 return 0;
}