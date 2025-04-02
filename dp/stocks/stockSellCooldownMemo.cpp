class Solution {
    int maxP(vector<int>&prices,int ind,int buy,int n,
    vector<vector<int>>&dp){
        if(ind>=n)return 0;
        if(dp[ind][buy]!=-1)return dp[ind][buy];
        if(buy){
            return dp[ind][buy]= max((-prices[ind]+
            maxP(prices,ind+1,0,n,dp)),
            (0+maxP(prices,ind+1,1,n,dp)));
        }else{
            return dp[ind][buy]=max((prices[ind]+
            maxP(prices,ind+2,1,n,dp)),
            (0+maxP(prices,ind+1,0,n,dp)));
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return maxP(prices,0,1,n,dp);
        
    }
};