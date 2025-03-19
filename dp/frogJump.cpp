#include <climits>
#include<iostream>
#include<vector>
using namespace std;
int frogJump(int index,vector<int>&heights,vector<int>&dp){
    if(index==0)return 0;
    if(dp[index]!=-1)return dp[index];
    int left = frogJump(index-1,heights,dp)+
    abs(heights[index]-heights[index-1]);
    int right = INT_MAX;
    if(index>1)right = frogJump(index-2,heights,dp)+
    abs(heights[index]-heights[index-2]);
    return dp[index]=min(left,right);
}
int main()
{
    vector<int>heights={30,10,60,10,60,50};
    vector<int>dp(6,-1);
    cout<<frogJump(5,heights,dp);
 return 0;
}