#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution {
    long long minPath(vector<vector<int>>& grid,int row,int col,vector<vector<int> >&dp){
        if(row==0 && col==0){
            return grid[row][col];
        };
        if(row<0 || col<0)return INT_MAX;
        if(dp[row][col]!=-1)return dp[row][col];
        long long up = grid[row][col]+minPath(grid,row-1,col,dp);
        long long left = grid[row][col]+minPath(grid,row,col-1,dp);
        return dp[row][col]=min(up,left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>>dp(row,vector<int>(col+1,-1));
        return minPath(grid,row-1,col-1,dp);
        
    }
};
int main()
{
    vector<vector<int>>grid={{1,3,1},{1,5,1},{4,2,1}};
    Solution obj;
    cout<<obj.minPathSum(grid);
 return 0;
}