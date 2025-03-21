#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int maxSum(vector<int>&arr,vector<int>&dp){
    dp[0]=arr[0];
    for(int i=1;i<arr.size();i++){
        int take=arr[i];
        if(i>1)take+=dp[i-2];
        int nonTake=0+dp[i-1];
        dp[i]=max(take,nonTake);
        
    }
    return dp[arr.size()-1];
}
int main()
{
    vector<int>arr={1,8,3,4,5};
    vector<int>dp(arr.size(),-1);
    cout<<maxSum(arr,dp);
 return 0;
}