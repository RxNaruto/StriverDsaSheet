class Solution {
    int lis(vector<int>&nums,int ind,int prev,int n
    ,vector<vector<int>>&dp){
        if(ind ==n)return 0;
        if(dp[ind][prev+1]!=-1)return dp[ind][prev+1];
        int l = 0+ lis(nums,ind+1,prev,n,dp);
        if(prev==-1 || nums[ind]>nums[prev]){
            l = max(l,1+lis(nums,ind+1,ind,n,dp));
        }

        return dp[ind][prev+1]=l;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return lis(nums,0,-1,n,dp);
        
    }
};