#include<iostream>
using namespace std;
int max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}
int maxSubarray(int arr[],int size){
    int sum=0,maxsum;
    for(int i=0;i<size;i++){
        for(int j=i;j<size;j++){
            sum=0;
            for(int k=i;k<j;k++){
                sum+=arr[k];
                 maxsum = max(sum,maxsum);
            }
        }
    }
    return maxsum;
    
}
int main()
{
     int arr[9]={-2,1,-3,4,-1,2,1,-5,4};
     cout<<maxSubarray(arr,9);
 return 0;
}