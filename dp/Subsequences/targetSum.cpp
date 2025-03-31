class Solution {
    
    public:
        int findTargetSumWays(vector<int>& nums, int target) {
            int sum=0;
            for(int i=0;i<nums.size();i++){
                sum+=nums[i];
            }
            if(sum-target<0 || (sum-target)%2!=0)return 0;
            int s2 = (sum-target)/2;
            vector<vector<int>>dp(nums.size(),vector<int>(s2+1,0));
            if(nums[0]==0)dp[0][0]=2;
            else dp[0][0]=1;
            if(nums[0]!=0 && nums[0]<=s2)dp[0][nums[0]]=1;
            for(int i=1;i<nums.size();i++){
                for(int t=0;t<=s2;t++){
                    int notTake = dp[i-1][t];
                    int take =0;
                    if(nums[i]<=t){
                        take = dp[i-1][t-nums[i]];
                    }
                    dp[i][t]=take+notTake;
             
                }
            }
            return dp[nums.size()-1][s2];
            
        }
    };