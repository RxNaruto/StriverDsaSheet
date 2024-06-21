#include<iostream>
using namespace std;

void swap(int arr[],int a,int b){
    int temp = arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}
void sort012(int arr[],int size){
    int low=0,high=size-1,mid=0;
 
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr,low,mid);
            low++;
            mid++;
        
        }
        else if(arr[mid]==1){
            mid++;
      
        }
        else{
            swap(arr,mid,high);
            high--;

        }
    }

}
int main()
{
    int arr[]={2,0,2,1,1,0};
    int size=sizeof arr/sizeof arr[0];
    sort012(arr,size );
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
 return 0;
}