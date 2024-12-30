#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution{
    public:
    int rottenOranges(vector<vector<int> >grid){
        int n = grid.size();
        int m = grid[0].size();
        //{{r,c},t}
        queue<pair<pair<int,int>,int> >q;
         vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else{
                    vis[i][j]=0;
                }
            }
        }
        int tm=0;
        int dRow[]={-1,0,1,0};
        int dCol[]={0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            tm = max(t,tm);
            for(int i=0;i<4;i++){
                int nrow = r+dRow[i];
                int ncol = c+dCol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]!=2 && grid[nrow][ncol]==1){
                    vis[nrow][ncol]=2;
                    q.push({{nrow,ncol},t+1});
                }
            }

        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]!=2 && grid[i][j]==1){
                    return -1;
                }
            }
        }
        return tm;
        
    }
};
int main()
{
  vector<vector<int>>oranges{
    {2,1,1},{0,1,1},{1,0,1}
  };
  Solution sol;
  cout<<sol.rottenOranges(oranges);
 return 0;
}