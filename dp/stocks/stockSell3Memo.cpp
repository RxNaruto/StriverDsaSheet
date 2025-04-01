class Solution {
    int maxP(vector<int>&prices,int ind,int buy,int cap,int n,vector<vector<vector<int>>>&dp){
        if(ind==n || cap==0)return 0;
        if(dp[ind][buy][cap]!=-1)return dp[ind][buy][cap];
        if(buy){
            return dp[ind][buy][cap]=max((-prices[ind]+maxP(prices,
            ind+1,0,cap,n,dp)),(0+maxP(prices,ind+1,1,cap,n,dp)));
        }
        else{
            return dp[ind][buy][cap]=max((prices[ind]+maxP(prices,
            ind+1,1,cap-1,n,dp)),(0+maxP(prices,ind+1,0,cap,n,dp)));
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>
        (2,vector<int>(3,-1)));
        return maxP(prices,0,1,2,n,dp);
        
    }
};