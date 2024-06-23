#include<iostream>
using namespace std;
int maxNumber(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}
void leadersInArray(int arr[],int size){
    int max=INT_MIN;
    for(int i = size-1;i>=0;i--){
        max= maxNumber(max,arr[i]);
        if(arr[i]>=max){
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