#include<iostream>
using namespace std;
void bubbleSort(int arr[],int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size-1;j++){
           if(arr[j]>arr[j+1]){
            int temp = arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
           }
        }
    }
}
int main()
{
    int arr[5]={5,4,3,2,1};
    int size = sizeof arr/sizeof arr[0];
    bubbleSort(arr,size);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
 return 0;
}