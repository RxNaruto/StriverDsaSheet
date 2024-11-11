#include<iostream>
#include<vector>
using namespace std;
int maxPoint(vector<int>arr,int k){
    int size = arr.size();
    int lsum =0,rsum=0;
    for(int i=0;i<k-1;i++){
        lsum=lsum+arr[i];

    }
    int maxE = INT_MIN;
    maxE = max(maxE,lsum);
    int j=size-1;
    for(int i=k-1;i>=0;i--){
        lsum = lsum-arr[i];
        rsum = rsum + arr[j];
        j--;
        maxE = max(maxE,lsum+rsum);


    }
    return maxE;
}
int main()
{
    vector<int>arr;
    arr.push_back(6);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(7);
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(7);
    arr.push_back(1);
    cout<<maxPoint(arr,4);
 return 0;
}