#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
    void combinatorSum(int arr[],int n,int target,vector<int>&ds,int index,vector<vector<int> >&ans){
        if(index==n){
            if(target==0){
                ans.push_back(ds);

            }
            return;
        }
        ds.push_back(arr[index]);
        combinatorSum(arr,n,target-arr[index],ds,index+1,ans);
        ds.pop_back();
        combinatorSum(arr,n,target,ds,index+1,ans);
        return;
    }

};
int main()
{
    Solution obj;
    int arr[]={10,1,2,7,6,1,5};
    int target=8;
    vector<int>ds;
    vector<vector<int> >ans;
    obj.combinatorSum(arr,7,target,ds,0,ans);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
 return 0;
}