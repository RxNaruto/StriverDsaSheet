#include <algorithm>
#include<iostream>
#include <numeric>
#include<vector>
using namespace std;
int checkSum(vector<int>arr,int k){
    int split=1,totalSum=0;
    int size = arr.size();
    for(int i=0;i<size;i++){
        if(totalSum+arr[i]<=k){
            totalSum+=arr[i];
        }
        else{
            split++;
            totalSum=arr[i];
        }
    }
    return split;

}
int splitArray(vector<int>arr,int k){
    int size = arr.size();
    int min = *max_element(arr.begin(),arr.end());
    int sum = accumulate(arr.begin(),arr.end(),0);
    for(int i= min;i<=sum;i++){
        if(checkSum(arr,i)==k){
            return i;
        }

    }
    return -1;

}
int main()
{
    vector<int>arr;
   
    arr.push_back(3);
    
    arr.push_back(5);
    arr.push_back(1);
    cout<<splitArray(arr,3);

 return 0;
}