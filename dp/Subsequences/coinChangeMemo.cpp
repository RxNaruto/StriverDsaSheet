class Solution {
    int countWays(int amount,vector<int>&coins,int index,vector<vector<int>>&dp){
        if(index==0){
            if(amount%coins[0]==0)return 1;
            else return 0;
        }
        if(dp[index][amount]!=-1)return dp[index][amount];
         int notTake = countWays(amount,coins,index-1,dp);
        int take = 0;
        if(coins[index]<=amount){
            take = countWays(amount-coins[index],coins,index,dp);
        }
        return dp[index][amount]=take+notTake;
    }
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        return countWays(amount,coins,coins.size()-1,dp);
        
    }
};