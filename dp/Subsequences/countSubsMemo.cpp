int findSum(vector<int>&arr,int target,int index,vector<vector<int>>&dp){
    if(target==0)return 1;
    if(index==0){
        if(arr[0]==target)return 1;
        return 0;
    }
	if(dp[index][target]!=-1)return dp[index][target];
    int notpick = findSum(arr,target,index-1,dp);
    int pick = 0;
    if(arr[index]<=target){
        pick = findSum(arr,target-arr[index],index-1,dp);
    }
    return dp[index][target]=pick+notpick;
}
int findWays(vector<int>& arr, int k)
{
	vector<vector<int>>dp(arr.size(),vector<int>(k+1,-1));
	return findSum(arr,k,arr.size()-1,dp);
	// Write your code here.
}
