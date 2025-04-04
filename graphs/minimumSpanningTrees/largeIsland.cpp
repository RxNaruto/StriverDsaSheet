#include<iostream>
#include<bits/stdc++.h>
#include<set>
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
    int maxConnection(vector<vector<int> >&grid){
        int n = grid.size();
        DisjointSet ds(n*n);
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                if(grid[r][c]==0)continue;
                int dr[]={-1,0,1,0};
                int dc[]={0,1,0,-1};

                for(int i=0;i<4;i++){
                    int nrow = r+dr[i];
                    int ncol = c+dc[i];

                    if(nrow>=0 && nrow<n && ncol >=0 && ncol<n && grid[nrow][ncol]==1){
                        int node = r*n + c;
                        int adjNode = nrow*n + ncol;
                        ds.unionBySize(node, adjNode);
                    }
                }
            }
        }
        int mx = 0;
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                if(grid[r][c]==1)continue;

                int dr[]={-1,0,1,0};
                int dc[]={0,1,0,-1};
                set<int>components;

                for(int i=0;i<4;i++){
                    int nrow = r+dr[i];
                    int ncol = c+dc[i];

                    if(nrow>=0 && nrow<n && ncol >=0 && ncol<n && grid[nrow][ncol]==1){
                         components.insert(ds.findUPar(nrow*n+ncol));
                    }
                }
                int sizeTotal = 0;
                for(auto it: components){
                    sizeTotal += ds.size[it];
                }
                mx = max(sizeTotal+1,mx);
            }
        }
        //if the grid has all the 1's
        for(int cell = 0;cell<n*n;cell++){
            mx = max(mx,ds.size[ds.findUPar(cell)]);
        }
        return mx;
    }
};
int main()
{
     vector<vector<int>> grid = {
        {1, 1, 0, 1, 1, 0}, {1, 1, 0, 1, 1, 0},
        {1, 1, 0, 1, 1, 0}, {0, 0, 1, 0, 0, 0},
        {0, 0, 1, 1, 1, 0}, {0, 0, 1, 1, 1, 0}
    };

    Solution obj;
    int ans = obj.maxConnection(grid);
    cout << "The largest group of connected 1s is of size: " << ans << endl;
    return 0;
 return 0;
}