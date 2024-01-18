#include<iostream>
using namespace std;
void RotateArray(int arr[],int size,int pos){
    for(int i=0;i<pos;i++){
        int temp=arr[0];
        for(int j=0;j<size;j++){
            arr[j]=arr[j+1];

            
        }
        arr[size-1]=temp;
    }
}
int main()
{
    int arr[5]={1,2,3,4,5};
    RotateArray(arr,5,2);
    for(int i=0;i<5;i++){
        cout<<arr[i];
    }
 return 0;
}