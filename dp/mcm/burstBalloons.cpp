class Solution {
    private:
    int maxC(vector<int>&nums,int i,int j){
        if(i>j)return 0;
        int maxi =INT_MIN;
        for(int ind=i;ind<=j;ind++){
            int cost = nums[ind]*nums[i-1]*nums[j+1]
            +maxC(nums,i,ind-1)+maxC(nums,ind+1,j);
            maxi = max(cost,maxi);
        }
        return maxi;
    }
public:
    int maxCoins(vector<int>& nums) {
        int size = nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        return maxC(nums,1,size);
        

        
    }
};