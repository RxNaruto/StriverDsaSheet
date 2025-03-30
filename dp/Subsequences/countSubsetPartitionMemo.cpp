
int subset(vector<int>&arr,int index,int k,vector<vector<int>>&dp){
    if(index==0){
        if(arr[0]==0 && k==0)return 2;
        if(k==0 || arr[0]==k)return 1;
        return 0;
    }
    if(dp[index][k]!=-1)return dp[index][k];
    int notTake = subset(arr,index-1,k,dp);
    int take = 0;
    if(arr[index]<=k){
        take =subset(arr,index-1,k-arr[index],dp);
    }
    return dp[index][k]=take+notTake;
}
int findWays(vector<int>& arr, int k)
{
    vector<vector<int>>dp(arr.size(),vector<int>(k+1,-1));
    return subset(arr,arr.size()-1,k,dp);
    
	
	
}
