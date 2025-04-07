class Solution {
    public:
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            int size = nums.size();
            int lastIndex =0;
            int maxi=1;
            sort(nums.begin(),nums.end());
            vector<int>dp(size,1);
            vector<int>hash(size);
            for(int i=0;i<size;i++){
                hash[i]=i;
                for(int prev=0;prev<i;prev++){
                    if(nums[i]%nums[prev]==0 && dp[i]<dp[prev]+1){
                        dp[i]=dp[prev]+1;
                        hash[i]=prev;
                    }
                }
                if(dp[i]>maxi){
                       maxi = dp[i];
                       lastIndex = i;
                   }
            }
            vector<int>temp;
            temp.push_back(nums[lastIndex]);
            while(hash[lastIndex]!=lastIndex){
                lastIndex = hash[lastIndex];
                temp.push_back(nums[lastIndex]);
            }
            return temp;
            
        }
    };