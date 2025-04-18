class Solution {
    
    public:
        int maxCoins(vector<int>& nums) {
            int size = nums.size();
            nums.insert(nums.begin(),1);
            nums.push_back(1);
            vector<vector<int>>dp(size+2,vector<int>(size+2,0));
            for(int i=size;i>=1;i--){
                for(int j=1;j<=size;j++){
                    if(i>j)continue;
                    int maxi =INT_MIN;
                    for(int ind=i;ind<=j;ind++){
                        int cost = nums[ind]*nums[i-1]*nums[j+1]
                        +dp[i][ind-1]+dp[ind+1][j];
                        maxi = max(cost,maxi);
                    }
                    dp[i][j]=maxi;
                }
            }
            return dp[1][size];
            
    
            
        }
    };