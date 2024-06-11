#include<iostream>
using namespace std;
int checkMax(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
int maxConsecutiveOne(int arr[],int size){
    int count=0,max=0;

    for(int i=0;i<size;i++){
        if(arr[i]==1){
           count++;
        }
        else{
            count=0;
        }
        max=checkMax(count,max);
    }
    
    return max;
}
int main()
{
    int arr[6]={1,1,0,1,1,1};
    cout<<"The max no. of 1's are "<<maxConsecutiveOne(arr,6);
 return 0;
}