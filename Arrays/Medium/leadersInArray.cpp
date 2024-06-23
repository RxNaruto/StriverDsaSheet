#include<iostream>
using namespace std;
void leadersInArray(int arr[],int size){
    for(int i=0;i<size;i++){
        int count=0;
        for(int j=i+1;j<size;j++){
            if(arr[i]<arr[j]){
                count=1;
                break;
            }
        }
        if(count==0){
            cout<<arr[i]<<" ";
        }
    }
}
int main()
{
    int  arr[6] = {10, 22, 12, 3, 0, 6};
    leadersInArray(arr,6);

 return 0;
}