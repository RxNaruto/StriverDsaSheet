#include<iostream>
using namespace std;

void SelectionSort(int arr[],int size){
  for(int i=0;i<size-1;i++){
    int min = i;
    for(int j=i;j<size;j++){
      if(arr[j]<arr[min]){
        min = j;
      }
    }
    int temp = arr[i];
    arr[i]=arr[min];
    arr[min]=temp;

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
    SelectionSort(arr,5);
    printingArr(arr,5);
 return 0;
}