#include<iostream>
using namespace std;
void bubbleSort(int arr[],int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size-1;j++){
           if(arr[j]>arr[j+1]){
            int temp = arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
           }
        }
    }
}
int max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}
int longestSubSeq(int arr[],int size){
    bubbleSort(arr,size);
    int lastSmaller = INT_MIN;
    int count=0;
    int longest=1;
    for(int i=0;i<size;i++){
        if(arr[i]-1==lastSmaller){
            count++;
            lastSmaller=arr[i];
        }
        else if(lastSmaller!=arr[i]){
            count=1;
            lastSmaller=arr[i];
        }
        longest = max(longest,count);
    }
    return longest;
}
int main()
{
    int arr[5]={3,8,5,7,6};
    cout<<longestSubSeq(arr,5);

 return 0;
}