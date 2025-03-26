#include<iostream>
#include<vector>
using namespace std;
int uniquePaths(vector<vector<int> >&grid,int row,int col,vector<vector<int> >&dp){
    if(row==0 && col==0)return 1;
    if(row<0 || col<0)return 0;
    if(dp[row][col]!=-1)return dp[row][col];
    int up=uniquePaths(grid,row-1,col,dp);
    int left=uniquePaths(grid,row,col-1,dp);
    return dp[row][col]=up+left;
}
int main()
{
    vector<vector<int> >grid={{0,0,0},{0,0,0},{0,0,0}};
    vector<vector<int> >dp(grid.size(),vector<int>(grid[0].size()+1,-1));
    cout<<uniquePaths(grid,2,2,dp);
 return 0;
}