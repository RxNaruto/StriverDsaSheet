#include<iostream>
#include<vector>
using namespace std;
int maxProductSubarray(vector<int>arr){
    int size=arr.size();
    int prefixSum =1,suffixSum=1;
    int maxE=INT_MIN;
    for(int i=0;i<size;i++){
        if(prefixSum==0)prefixSum=1;
        if(suffixSum==0)suffixSum=1;
        prefixSum*=arr[i];
        suffixSum*=arr[size-i-1];
        maxE = max(maxE,max(prefixSum,suffixSum));
        
    }
    return maxE;
}
int main()
{
    vector<int>arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(-3);
    arr.push_back(0);
    arr.push_back(-4);
    arr.push_back(-5);
    cout<<maxProductSubarray(arr);
 return 0;
}