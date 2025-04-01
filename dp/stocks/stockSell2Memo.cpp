class Solution {
    private:
    int maxP(vector<int>&prices,int ind,int buy,int n,
    vector<vector<int>>&dp){
        if(ind==n)return 0;
        int profit = 0;
        if(dp[ind][buy]!=-1)return dp[ind][buy];
        if(buy){
            profit= max((-prices[ind]+maxP(prices,ind+1,0,n,dp)),
            (0+maxP(prices,ind+1,1,n,dp)));
        }
        else{
            profit= max((prices[ind]+maxP(prices,ind+1,1,n,dp)),
            (0+maxP(prices,ind+1,0,n,dp)));
        }
        return dp[ind][buy]=profit;
    }
    

public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return maxP(prices,0,1,n,dp);
        
        
    }
};