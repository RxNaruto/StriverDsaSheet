class Solution {
    private:
    int maxC(vector<int>&nums,int i,int j,vector<vector<int>>&dp){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int maxi =INT_MIN;
        for(int ind=i;ind<=j;ind++){
            int cost = nums[ind]*nums[i-1]*nums[j+1]
            +maxC(nums,i,ind-1,dp)+maxC(nums,ind+1,j,dp);
            maxi = max(cost,maxi);
        }
        return dp[i][j]=maxi;
    }
public:
    int maxCoins(vector<int>& nums) {
        int size = nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return maxC(nums,1,size,dp);
        

        
    }
};