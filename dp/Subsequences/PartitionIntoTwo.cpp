class Solution {
    public:
        int minimumDifference(vector<int>& nums) {
            int totSum=0;
            for(int i=0;i<nums.size();i++){
                totSum+=nums[i];
            }
            int k=totSum;
            vector<vector<bool>>dp(nums.size(),vector<bool>(k+1,false));
            for(int i=0;i<nums.size();i++){
                dp[i][0]=true;
            }
            if(nums[0]>=0 && nums[0]<=k){
                dp[0][nums[0]]=true;
            }
            for(int i=1;i<nums.size();i++){
                for(int target=1;target<=k;target++){
                    bool notTake = dp[i-1][target];
                    bool take = false;
                    if(nums[i]<=target){
                        take =dp[i-1][target-nums[i]];
                    }
                    dp[i][target]=take || notTake;
                }
            }
            int minE= 1e9;
            for(int i=0;i<= totSum/2;i++){
                if(dp[nums.size()-1][i]==true){
                    int s1 = i;
                    int s2 = totSum-s1;
                    minE=min(minE,abs(s1-s2));
                }
            }
            return minE;
            
        }
    };