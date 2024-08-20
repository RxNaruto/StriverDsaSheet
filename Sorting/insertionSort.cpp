#include<iostream>
using namespace std;
void insertionSort(int arr[],int size){
    for(int i=0;i<size;i++){
        int j=i;
        while(j>0 && arr[j]<arr[j-1]){
            int temp = arr[j-1];
            arr[j-1]=arr[j];
            arr[j] = temp;
            j--;
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
    insertionSort(arr,5);
    printingArr(arr,5);
 return 0;
}