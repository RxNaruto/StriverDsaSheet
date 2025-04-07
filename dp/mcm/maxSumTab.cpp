class Solution {
    public:
        int maxSumAfterPartitioning(vector<int>& arr, int k) {
            vector<int>dp(arr.size()+1,0);
            
            dp[arr.size()]=0;
            for(int i=arr.size()-1;i>=0;i--){
                int maxA=INT_MIN;
                int len=0,maxi=INT_MIN;
                for(int j=i;j<min((int)arr.size(),i+k);j++){
                    len++;
                    maxi = max(maxi,arr[j]);
                    int sum = (len*maxi)+dp[j+1];
                    maxA=max(sum,maxA);
                }
                dp[i]=maxA;
            }
            return dp[0];
            
        }
    };