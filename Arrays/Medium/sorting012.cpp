#include<iostream>
using namespace std;
void sort012(int arr[],int size){
    int c0=0,c1=0,c2=0;
    for(int i=0;i<size;i++){
        if(arr[i]==0){
            c0++;
        }
        else if(arr[i]==1){
            c1++;
        }
        else{
            c2++;
        }
    }
    for(int i=0;i<c0;i++){
        arr[i]=0;
    }
    for(int i=c0;i<c0+c1;i++){
        arr[i]=1;
    }
    for(int i=c0+c1;i<c0+c1+c2;i++){
        arr[i]=2;
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