class Solution {
    
    public:
        int lengthOfLIS(vector<int>& nums) {
            int n = nums.size();
            vector<int>next(n+1,0),curr(n+1,0);
            for(int prev = 0;prev<i;prev++){
                if(arr[prev]<arr[i]){
                    dp[i]=max(dp[i],1+dp[prev]);
                }
            }
            maxi = max(maxi,dp[i]);
            
        }
        return maxi;
    };