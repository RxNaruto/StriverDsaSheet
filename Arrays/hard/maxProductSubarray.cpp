#include<iostream>
#include<vector>
using namespace std;
int maxProductSubArray(vector<int>arr){
    int maxP = INT_MIN;
    int size = arr.size();
    for(int i=0;i<size-1;i++){
        int product = arr[i];
        for(int j=i+1;j<size;j++){
            product*=arr[j];
                maxP =max(maxP,product);
        }
    }
    return maxP;
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
    cout<<maxProductSubArray(arr);

 return 0;
}