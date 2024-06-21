#include<iostream>
#include<map>
using namespace std;
vector<int>twoSum(vector<int>&nums,int target){
    map<int,int>mpp;
    int n= nums.size();
    for(int i=0;i<n;i++){
        int a = nums[i];
        int requiredNum = target-a;
        if(mpp.find(requiredNum)!=mpp.end()){
            return {mpp[requiredNum],i};
        }
        mpp[a] = i;
    }
    return{-1,-1};

}
int main()
{
 return 0;
}