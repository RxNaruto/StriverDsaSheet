class Solution {
    // private:
    // int maxP(vector<int>&prices,int ind,int buy,int n,
    // vector<vector<int>>&dp){
    //     if(ind==n)return 0;
    //     int profit = 0;
    //     if(dp[ind][buy]!=-1)return dp[ind][buy];
    //     if(buy){
    //         profit= max((-prices[ind]+maxP(prices,ind+1,0,n,dp)),
    //         (0+maxP(prices,ind+1,1,n,dp)));
    //     }
    //     else{
    //         profit= max((prices[ind]+maxP(prices,ind+1,1,n,dp)),
    //         (0+maxP(prices,ind+1,0,n,dp)));
    //     }
    //     return dp[ind][buy]=profit;
    // }
    

public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>ahead(2,0);
        vector<int>curr(2,0);
        ahead[1]=ahead[0]=0;
        
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                int profit =0;
                if(buy){
                    profit= max((-prices[ind]+ahead[0]),
                    (0+ahead[1]));
                }
                else{
                    profit= max((prices[ind]+ahead[1]),
                    (0+ahead[0]));
                }
                curr[buy]=profit;
                    
            }
            ahead =curr;
        }
        return ahead[1];
        
        
    }
};