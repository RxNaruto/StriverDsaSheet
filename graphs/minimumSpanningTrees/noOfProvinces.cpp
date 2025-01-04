#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    public:
     vector<int>rank,parent,size;
    DisjointSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1,0);
        parent.resize(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findUPar(int node){
        if(node==parent[node]){
            return node;

        }
        return parent[node]=findUPar(parent[node]);
    }
    void unionByRank(int u,int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v)return;
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]= ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u,int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v)return;
        if(size[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]= ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};
class Solution{
    public:
    int numOfProvinces(vector<vector<int> >adj,int V){
        DisjointSet ds(V);
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==1){
                    ds.unionBySize(i,j);

                }
            }
        }
        int cnt=0;
        for(int i=0;i<V;i++){
            if(ds.parent[i]==i)cnt++;
        }
        return cnt;

    }
};
int main()
{
    int V = 9;
    vector<vector<int>> edge = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {2, 3}, {4, 5}, {5, 6}, {7, 8}};

    // Convert edge list to adjacency matrix
    vector<vector<int>> adj(V, vector<int>(V, 0));
    for (auto it : edge) {
        adj[it[0]][it[1]] = 1;
        adj[it[1]][it[0]] = 1;
    }

    Solution obj;
    int ans = obj.numOfProvinces(adj, V);
    cout << "The number of provinces: " << ans << endl;
 return 0;
}