class Solution {
    int lis(vector<int>&nums,int ind,int prev,int n){
        if(ind ==n)return 0;
        
        int l = 0+ lis(nums,ind+1,prev,n);
        if(prev==-1 || nums[ind]>nums[prev]){
            l = max(l,1+lis(nums,ind+1,ind,n));
        }

        return l;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        return lis(nums,0,-1,n);
        
    }
};