#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    vector<int>rank,parent,size;
    public:
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
    vector<int>noOfIsland(int n,int m,vector<vector<int> > &operators){
        DisjointSet ds(n*m);
        vector<vector<int> > vis(n,vector<int>(m,0));
        vector<int>ans;
        int cnt=0;
        for(auto it: operators){
            int row = it[0];
            int col = it[1];
            if(vis[row][col]==1){
                ans.push_back(cnt);
                continue;
            }
            cnt++;
            vis[row][col]=1;
            int dr[]={-1,0,1,0};
            int dc[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int nrow = row+dr[i];
                int ncol = col+dc[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==1){
                    int nNode = row* m + col ;
                    int adjNode = nrow*m + ncol;
                    if(ds.findUPar(nNode)!=ds.findUPar(adjNode)){
                        cnt--;
                        ds.unionBySize(nNode,adjNode);
                    }
                }
            }
            ans.push_back(cnt);
        }
        
        return ans;

    }
};
int main()
{

    int n = 4, m = 5;
    vector<vector<int>> operators = {{0, 0}, {0, 0}, {1, 1}, {1, 0}, {0, 1},
        {0, 3}, {1, 3}, {0, 4}, {3, 2}, {2, 2}, {1, 2}, {0, 2}
    };


    Solution obj;
    vector<int> ans = obj.noOfIsland(n, m, operators);
    for (auto res : ans) {
        cout << res << " ";
    }
    cout << endl;
    return 0;
 return 0;
}