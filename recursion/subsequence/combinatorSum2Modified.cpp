#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
    public:
    void combinatorSum(vector<int>&arr,int n,int target,vector<int>&ds,int index,vector<vector<int> >&ans){
        if(target==0){
                ans.push_back(ds);
                return;

        }
        for(int i=index;i<n;i++){
            if(i>index && arr[i]==arr[i-1])continue;
            if(arr[i]>target)break;
            ds.push_back(arr[i]);
            combinatorSum(arr,n,target-arr[i],ds,i+1,ans);
            ds.pop_back();

        }

    }

};
int main()
{
    Solution obj;
    vector<int>arr={10,1,2,7,6,1,5};
    int target=8;
    vector<int>ds;
    vector<vector<int> >ans;
    sort(arr.begin(),arr.end());
    obj.combinatorSum(arr,7,target,ds,0,ans);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
 return 0;
}