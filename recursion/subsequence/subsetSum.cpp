#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
    void subsetSum(vector<int>arr,int i,int n,int &sum,vector<int>&ans){
        if(i==n){
            ans.push_back(sum);
            return;
        }
        sum+=arr[i];
        subsetSum(arr,i+1,n,sum,ans);
        sum-=arr[i];
        subsetSum(arr,i+1,n,sum,ans);
    
    }
};
int main()
{
    Solution obj;
    vector<int>arr={3,1,4};
    int n=3;
    int sum=0;
    vector<int>ans;
    obj.subsetSum(arr,0,n,sum,ans);
    for(auto it: ans){
        cout<<it<<" ";
    }

 return 0;
}