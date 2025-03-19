#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
    public:
    void subsetSum(int index,int n,vector<int>&ds,vector<int>arr,vector<vector<int>>&ans){
        ans.push_back(ds);
        for(int i=index;i<n;i++){
            if(i>index && arr[i]==arr[i-1])continue;
            ds.push_back(arr[i]);
            subsetSum(i+1,n,ds,arr,ans);
            ds.pop_back();

        }
    }
};
int main()
{
    Solution obj;
    vector<int>arr={3,1,4};
    int n=3;
    int sum=0;
    vector<int>ds;
    vector<vector<int>>ans;
    sort(arr.begin(),arr.end());
    obj.subsetSum(0,n,ds,arr,ans);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";

        }
        cout<<endl;
    }
 return 0;
}