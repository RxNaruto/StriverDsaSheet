class Solution {
    
    public:
        int coinChange(vector<int>& coins, int amount){
            vector<vector<int>>dp(coins.size(),vector<int>(amount+1,0));
            for(int i=0;i<=amount;i++){
                if(i%coins[0]==0){
                    dp[0][i]=i/coins[0];
                }
                else{
                    dp[0][i]=1e9;
                }
            }
            for(int i=1;i<coins.size();i++){
                for(int t=0;t<=amount;t++){
                    int notTake = 0+ dp[i-1][t];
                    int take = INT_MAX;
                    if(coins[i]<=t){
                        take = 1 + dp[i][t-coins[i]];
                    }
                    dp[i][t]=min(take,notTake);
                }
            }
            if(dp[coins.size()-1][amount]==1e9)return -1;
            return dp[coins.size()-1][amount];
             
        }
    };