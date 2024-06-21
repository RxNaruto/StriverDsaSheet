#include<iostream>
using namespace std;
void Sort012(int arr[],int size){
    
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(arr[0]==0 || arr[0]==1){
                continue;
            }
            if(arr[j]==0){
                int temp= arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
            }
            else if(arr[j]==2){
                int temp= arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
            
        }
    }
}
int main()
{
    int arr[6]={2,0,2,1,1,0};
    Sort012(arr,  6);
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
 return 0;
}