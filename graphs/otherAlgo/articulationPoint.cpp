#include<iostream>
#include<vector>
using namespace std;
class Solution{
    private:
    int timer = 0;
    private:
    void dfs(int node,int parent,vector<int>&vis,vector<int>adj[],vector<int>&tin,vector<int>&low,vector<int>&mark){
        vis[node]=1;
        tin[node]=low[node]=timer;
        timer++;
        int child = 0;
        for(auto it: adj[node]){
            if(!vis[it]){
                if(it==parent)continue;
                dfs(it,node,vis,adj,tin,low,mark);
                low[node]=min(low[node],low[it]);
                if(low[it]>=tin[node]&& parent!=-1){
                    mark[node]=1;
                }
                child++;
            }
            else{
                low[node]= min(low[node],tin[it]);
            }

        }
        if(child>1 && parent== -1){
            mark[node]=1;
        }

         
    }
    public:
    vector<int>articulationPoint(int n,vector<int>adj[]){
        vector<int>vis(n,0);
        vector<int>tin(n,0),low(n,0);
        vector<int>mark(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,-1,vis,adj,tin,low,mark);
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(mark[i]==1){
                ans.push_back(i);
            }
        }
        if(ans.size()==0)return{-1};
        return ans;
        
        
    }
};
int main()
{
     int n = 5;
    vector<vector<int>> edges = {
        {0, 1}, {1, 4},
        {2, 4}, {2, 3}, {3, 4}
    };

    vector<int> adj[n];
    for (auto it : edges) {
        int u = it[0], v = it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Solution obj;
    vector<int> nodes = obj.articulationPoint(n, adj);
    for (auto node : nodes) {
        cout << node << " ";
    }
    cout << endl;
 return 0;
}