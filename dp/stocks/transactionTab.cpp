class Solution {
    int maxP(vector<int>&prices,int ind,int buy,int n,
     vector<vector<int>>&dp,int fee){
         if(ind==n)return 0;
         if(dp[ind][buy]!=-1)return dp[ind][buy];
         if(buy){
             return max((-prices[ind]+maxP(prices,ind+1,0,n,dp,fee)),
             (0+maxP(prices,ind+1,1,n,dp,fee)));
         }
         else{
             return max((prices[ind]-fee+maxP(prices,ind+1,1,n,dp,fee)),
             (0+maxP(prices,ind+1,0,n,dp,fee)));
         }
     }
 public:
     int maxProfit(vector<int>& prices, int fee) {
         int n = prices.size();
         vector<vector<int>>dp(n+1,vector<int>(2,-1));
         dp[n][0]=dp[n][1]=0;
         for(int i=n-1;i>=0;i--){
             for(int buy = 0;buy<2;buy++){
                 if(buy){
                     dp[i][buy]=max((-prices[i]+dp[i+1][0]),
                     (0+dp[i+1][1]));
                 }
                 else{
                     dp[i][buy]=max((prices[i]-fee+dp[i+1][1])
                     ,(0+dp[i+1][0]));
                 }
             }
         }
         return dp[0][1];
         
     }
 };