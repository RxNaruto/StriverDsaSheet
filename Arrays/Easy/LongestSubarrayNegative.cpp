#include<iostream>
using namespace std;
int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
int longestSubarray(int arr[],int k,int size){
    int sum=0;
    int len=0;
    for(int i=0;i<size;i++){
        for(int j=i;j<size;j++){
            sum=sum+arr[j];
            if(sum==k){
            len=max(len,j-i+1);
        }

        }
        
    }
    return len;
}
int main()
{
    int arr[3]={1,-1,1};
    cout<<"The longest subarray is "<<longestSubarray(arr,1,3);
 return 0;
}