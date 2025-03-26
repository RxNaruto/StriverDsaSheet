#include<iostream>
#include<vector>
using namespace std;
class Solution {
    private:
    int maxSum(vector<int>&arr){
    int prev1=arr[0];
    int prev2=0;
    for(int i=1;i<arr.size();i++){
        int take=arr[i];
        if(i>1)take+=prev2;
        int nonTake=0+prev1;
        int curr=max(take,nonTake);
        prev2=prev1;
        prev1=curr;
     
        
    }
    return prev1;
}
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size==1)return nums[0];
        vector<int>temp1;
        vector<int>temp2;

        for(int i=0;i<size;i++){
            if(i!=0){
                temp1.push_back(nums[i]);
            }
            if(i!=size-1){
                temp2.push_back(nums[i]);
            }
        }
        return max(maxSum(temp1)v,maxSum(temp2));
        
        
    }
};
int main()
{
    vector<int>arr={1,2,1,1};
    Solution obj;
    cout<<obj.rob(arr);

 return 0;
}