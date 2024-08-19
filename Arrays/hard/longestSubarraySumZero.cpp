#include<iostream>
#include<vector>
using namespace std;
int maxf(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}
int longestSubArrayWithSumZero(vector<int>arr){
    int size = arr.size();
    int max=0,count=1;
    int sum = 0;
    for(int i=0;i<size-1;i++){
        if(arr[i]==0){
            max = maxf(1,max);
        }
        sum=arr[i];
        for(int j=i+1;j<size;j++){
            sum = arr[j]+sum;
            count++;
            if(sum==0){
                max = maxf(count,max);
                
        
            }
        }
        count=1;
    }
    return max;
}
int main()
{
    vector<int>arr;
    arr.push_back(6);
    arr.push_back(-2);
    arr.push_back(2);
    arr.push_back(-8);
    arr.push_back(1);
    arr.push_back(7);
    arr.push_back(4);
    arr.push_back(-10);
    
    
    cout<<longestSubArrayWithSumZero(arr);
 return 0;
}