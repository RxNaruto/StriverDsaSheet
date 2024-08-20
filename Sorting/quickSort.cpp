#include<iostream>
using namespace std;
int partitionEl(int arr[],int low,int high){
    int pivot = arr[low];
    int i=low;
    int j=high;

    while(i<j){
        while(i<=high-1 && arr[i]<=pivot){
            i++;
        }
        while(j>low && arr[j]>=pivot){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }

    }
    swap(arr[low],arr[j]);
    return j;

}
void quickSort(int arr[],int low,int high){
    if(low<high){
        int pivot = partitionEl(arr,low,high);
        quickSort(arr,low,pivot-1);
        quickSort(arr,pivot+1,high);

    }
}
int main()
{
    int arr[5]={5,4,3,2,1};
    quickSort(arr,0,4);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
 return 0;
}