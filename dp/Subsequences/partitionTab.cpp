class Solution {
    public:
        bool canPartition(vector<int>& nums) {
            int n= nums.size();
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=nums[i];
            }
            if(sum%2!=0)return false;
            int tg=sum/2;
            vector<vector<bool>>dp(n,vector<bool>(tg+1,false));
            for(int i=0;i<n;i++){
                dp[i][0]=true;
            }
            if(nums[0]<=tg)dp[0][nums[0]]=true;
            for(int index=1;index<n;index++){
                for(int target=1;target<=tg;target++){
                    bool notTake = dp[index-1][target];
                    bool take = false;
                    if(target>=nums[index]){
                        take = dp[index-1][target-nums[index]];
                    }
                    dp[index][target]=take || notTake;
    
                }
            }
            return dp[n-1][tg];
            
        }
    };