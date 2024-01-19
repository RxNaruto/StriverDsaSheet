#include<iostream>
using namespace std;
void Sorting(int arr[],int size){
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-1;j++){
            if(arr[j]==0){
                int temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
            }
            else if(arr[j]==2){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }

    }
}
int main()
{
    int arr[3]={2,0,1};
    Sorting(arr,3);
    for(int i=0;i<3;i++){
        cout<<arr[i];
    }
 return 0;
}