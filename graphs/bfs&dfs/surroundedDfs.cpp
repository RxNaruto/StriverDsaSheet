#include<iostream>
#include<vector>
using namespace std;
class Solution{
    private:
      void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>grid){
        vis[row][col]=1;
        int n = grid.size();
        int m = grid[0].size();
        int dRow[] = {-1,0,1,0};
        int dCol[] = {0,1,0,-1};
         for(int i=0;i<4;i++){
            int nrow = row + dRow[i];
            int ncol = col+ dCol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]=='O'){
                dfs(nrow,ncol,vis,grid);
            }

         }
         
      }

    public:
    vector<vector<char>>surroundedDfs(int n,int m,vector<vector<char>>grid){
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            if(grid[0][j]=='O' && !vis[0][j]){
                dfs(0,j,vis,grid);
            }
            if(grid[n-1][j]=='O' && !vis[n-1][j]){
                dfs(n-1,j,vis,grid);
            }
        }
        for(int i=0;i<n;i++){
            if(grid[i][0]=='O' && !vis[i][0]){
                dfs(i,0,vis,grid);
            }
            if(grid[i][m-1]=='O' && !vis[i][m-1]){
                dfs(i,m-1,vis,grid);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='O'){
                    grid[i][j]='X';
                }
            }
        }
        return grid;



    }
};
int main()
{
    vector<vector<char>> mat{
        {'X', 'X', 'X', 'X'}, 
        {'X', 'O', 'X', 'X'}, 
        {'X', 'O', 'O', 'X'}, 
        {'X', 'O', 'X', 'X'}, 
        {'X', 'X', 'O', 'O'}
    };
    
    Solution ob;
    // n = 5, m = 4
    vector<vector<char>> ans = ob.surroundedDfs(5, 4, mat);
    for(int i = 0;i < 5;i++) {
        for(int j = 0;j < 4;j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
 return 0;
}