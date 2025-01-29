#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution{
    public:
    int noOfEnclave(vector<vector<int>>grid){
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;
        //{row,col}
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(grid[0][i]==1 && !vis[0][i]){
                q.push({0,i});
                vis[0][i]=1;
            }
            if(grid[n-1][i]==1 && !vis[n-1][i]){
                q.push({n-1,i});
                vis[n-1][i]=1;
            }
        }
        for(int j=0;j<n;j++){
            if(grid[j][0]==1 && !vis[j][0]){
                q.push({j,0});
                vis[j][0]=1;
            }
            if(grid[j][m-1]==1 && !vis[j][m-1]){
                q.push({j,m-1});
                vis[j][m-1]=1;

            }
        }
        int dRow[]={-1,0,1,0};
        int dCol[]={0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = r+dRow[i];
                int ncol = c+dCol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }

        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
int main()
{
    vector<vector<int>> grid{
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}};
        
    Solution obj;
    cout << obj.noOfEnclave(grid) << endl;
 return 0;
}