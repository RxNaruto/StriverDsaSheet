#include <algorithm>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution{
    private:
    void bfs(int row,int col,vector<vector<char>>&grid,vector<vector<int>>&vis){
        vis[row][col]=1;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;
        q.push({row,col});
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int drow=-1;drow<=1;drow++){
                for(int dcol=-1;dcol<=1;dcol++){
                    if(drow == 0 && dcol==0)continue;
                    int nrow = row+drow;
                    int ncol = col+dcol;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
                         vis[nrow][ncol]=1;
                         q.push({nrow,ncol});

                    }
                    
                }
            }

        }

    }
    public:
    int numIsland(vector<vector<char>>&grid){
        int n = grid.size();
        int m = grid[0].size();
        int count =0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    bfs(i,j,grid,vis);
                    count++;
                }
            }
        }
        return count;

    }


};
int main()
{
    vector<vector<char>> grid
    {
        {'0', '1', '1', '1', '0', '0', '0'},
        {'0', '0', '1', '1', '0', '1', '0'}
    };

        
    Solution obj;
    cout << obj.numIsland(grid) << endl;

 return 0;
}