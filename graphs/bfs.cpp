#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int>bfs(int v,vector<int>adj[]){
    vector<int>vis(v+1,0);
    vis[1]=1;
    queue<int>q;
    q.push(1);
    vector<int>ans;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }

    }
    return ans;
}

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
    vector<int>ans = bfs(n,adj);
    for(int it: ans){
        cout<<it<<" ";
    }


 return 0;
}