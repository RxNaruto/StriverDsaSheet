#include<iostream>
#include<vector>
using namespace std;
class Solution{
    private:
    void dfs(int v,vector<int>adj[],vector<int>&ans,vector<int>&vis){
        vis[v]=1;
        ans.push_back(v);
        for(auto it: adj[v]){
            if(!vis[it]){
                dfs(it,adj,ans,vis);
            }

        }
        
    }

    public:
    vector<int>dfsOfGraph(int v,vector<int>adj[]){
        vector<int>vis(v+1,0);
        int start =1;
        vector<int>ans;
        dfs(start,adj,ans,vis);
        return ans;



    }
};
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Solution sol;
    vector<int>ans = sol.dfsOfGraph(n, adj);
    for(auto it: ans){
        cout<<it<<" ";
    }
 return 0;
}