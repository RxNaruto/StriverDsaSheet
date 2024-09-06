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
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);
    while(low<=high){
        int mid = (low+high)/2;
        if(checkSum(arr,mid)>k){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return low;

}
int main()
{
    vector<int>arr;
   
    arr.push_back(5);
    
    arr.push_back(5);
    arr.push_back(5);
    arr.push_back(5);
    cout<<splitArray(arr,2);

 return 0;
}