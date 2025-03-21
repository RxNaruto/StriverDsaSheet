#include<iostream>
#include<vector>
using namespace std;
int maxSum(vector<int>&arr,int index,vector<int>&dp){
    if(index==0)return arr[index];
    if(index<0)return 0;
    if(dp[index]!=-1)return dp[index];
    int pick = arr[index]+maxSum(arr,index-2,dp);
    int notPick = 0+maxSum(arr,index-1,dp);
    return dp[index]=max(pick,notPick);
}
int main()
{
    vector<int>arr={1,2,3,4,5};
    vector<int>dp(arr.size(),-1);
    cout<<maxSum(arr,arr.size()-1,dp);
 return 0;
}