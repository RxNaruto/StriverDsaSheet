class Solution {
    int maxS(vector<int>&arr,int k,int ind,int n,vector<int>&dp){
        if(ind ==n)return 0;
        if(dp[ind]!=-1)return dp[ind];
        int maxA=INT_MIN;
        int len=0,maxi=INT_MIN;
        for(int j=ind;j<min(n,ind+k);j++){
            len++;
            maxi = max(maxi,arr[j]);
            int sum = (len*maxi)+maxS(arr,k,j+1,n,dp);
            maxA=max(sum,maxA);
        }
        return dp[ind]=maxA;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size(),-1);
        return maxS(arr,k,0,arr.size(),dp);
        
    }
};