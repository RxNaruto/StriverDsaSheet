#include<iostream>
#include<vector>
using namespace std;
class Solution{
    private:
    int timer =1;
    private:
    void dfs(int node,int parent,vector<int>adj[],vector<int>&vis,vector<int>&tin,vector<int>&low,vector<vector<int> > &bridges){
        vis[node]=1;
        tin[node]=low[node]=timer;
        timer++;
        for(auto it: adj[node]){
            if(it==parent)continue;
            if(vis[it]==0){
                dfs(it,node,adj,vis,tin,low,bridges);
                low[node]=min(low[node],low[it]); 
                //node--it
                if(low[it]>tin[node]){
                    bridges.push_back({it,node});
                }
                
            }
            else{
                    low[node]=min(low[node],low[it]);
                }
        }
    }
    public:
    vector<vector<int> > criticalConnection(int n, vector<vector<int > > &connection){
        vector<int>adj[n];
        for(auto it: connection){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
             
        }
        vector<int>tin(n);
        vector<int>low(n);
        vector<int>vis(n,0);
        vector<vector<int> > bridges;
        dfs(0,-1,adj,vis,tin,low,bridges);
        return bridges;
    }
};
int main()
{
    int n = 4;
    vector<vector<int>> connections = {
        {0, 1}, {1, 2},
        {2, 0}, {1, 3}
    };

    Solution obj;
    vector<vector<int>> bridges = obj.criticalConnection(n, connections);
    for (auto it : bridges) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
 return 0;
}