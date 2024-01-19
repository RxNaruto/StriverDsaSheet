#include<iostream>
using namespace std;
void sorting(int arr[],int size){
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size;j++){
             if(arr[j]==2){
            int temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
            
        }
        else if(arr[j]==0){
            int temp=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;
           

        }
        else{
            i++;
        }
        }

       
    }
}
int main()
{
    int arr[5]={0,1,2,0,1};
    sorting(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i];
    }
 return 0;
}