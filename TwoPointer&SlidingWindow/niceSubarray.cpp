#include<iostream>
#include<vector>
using namespace std;
int niceSubArray(vector<int>arr,int k){
    int size = arr.size();
    int l=0,r=0,cnt=0,sum=0;
    while(r<size){
        sum = sum+arr[r]%2;
        while(sum>k){
            sum = sum-arr[l]%2;
            l++;
        }
        cnt = cnt+(r-l+1);
        r++;
    }
    return cnt;
}

int main()
{
    vector<int>arr;
   
    arr.push_back(2);
    arr.push_back(4);
    arr.push_back(6);
    cout<<niceSubArray(arr,1)-niceSubArray(arr,0);
 return 0;
}