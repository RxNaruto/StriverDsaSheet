#include<iostream>
#include<vector>
using namespace std;
class Solution{
    private:
    void dfs(int v,vector<int>arr[],vector<int>&vis){
        vis[v]=1;
        for(auto it: arr[v]){
            if(!vis[it]){
                dfs(it,arr,vis);
            }

        }

    }
    public:
    int province(int v,vector<int>arr[]){
        int count =0;
        vector<int>vis(v+1,0);
        for(int i=1;i<vis.size();i++){
            if(!vis[i]){
                count++;
                dfs(i,arr,vis);
            }
        }
        return count;
    }
};
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>arr[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    Solution sol;
    cout<<sol.province(n,arr);


 return 0;
}