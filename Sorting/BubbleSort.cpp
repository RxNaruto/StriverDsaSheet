#include<iostream>
using namespace std;
void bubbleSort(int arr[],int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]= temp;
            }
        }
    }
}
void printingArr(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int arr[5]={5,4,3,2,1};
    printingArr(arr,5);
    bubbleSort(arr,5);
    printingArr(arr,5);

 return 0;
}