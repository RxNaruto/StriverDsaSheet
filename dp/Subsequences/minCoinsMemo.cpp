class Solution {
    int coinsC(vector<int>&arr,int index,int amount,vector<vector<int>>&dp){
        if(index==0){
            if(amount%arr[0]==0){
                return amount/arr[0];
            }
            else return 1e9;
        }
        if(dp[index][amount]!=-1)return dp[index][amount];
        int notTake = 0+coinsC(arr,index-1,amount,dp);
        int take = INT_MAX;
        if(arr[index]<=amount){
            take = 1+coinsC(arr,index,amount-arr[index],dp);
        }
        return dp[index][amount]=min(take,notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount){
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        int ans = coinsC(coins,coins.size()-1,amount,dp);
        if(ans>=1e9)return -1;
        return ans;
        
    }
};