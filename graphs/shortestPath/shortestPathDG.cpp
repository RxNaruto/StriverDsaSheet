#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class Solution{
    private:
    void topoSort(int node,vector<pair<int,int> >adj[],vector<int>&vis,stack<int>&st){
        vis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it.first]){
                topoSort(it.first,adj,vis,st);
            }
        }
        st.push(node);
    }
    public:
    vector<int>shortestPath(int n,int m, vector<vector<int > >&edges,int src){
        vector<pair<int,int> >adj[n];
        for(int i=0;i<m;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
        }
        vector<int>vis(n,0);
        stack<int>st;
        for(int i=0;i<n;i++){
            topoSort(i,adj,vis,st);
        }
        vector<int>dist(n,1e9);
        dist[src]=0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            for(auto it: adj[node]){
                int v = it.first;
                int wt = it.second;
                if(dist[node]+wt<dist[v]){
                    dist[v]=dist[node]+wt;
                }
            }
           
            


        }
         for(int i=0;i<n;i++){
                if(dist[i]==1e9){
                    dist[i]=-1;
                }

            }
        return dist;
        

    }
};
int main()
{
    int N = 6, M = 7;
  
  vector<vector<int>> edges= {{0,1,2},{0,4,1},{4,5,4},{4,2,2},{1,2,3},{2,3,6},{5,3,1}};
  Solution obj;
  vector < int > ans = obj.shortestPath(N, M, edges,0);

  for (int i = 0; i < ans.size(); i++) {

    cout << ans[i] << " ";
  }
 return 0;
}