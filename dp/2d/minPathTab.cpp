#include<iostream>
#include<vector>
using namespace std;
int minPath(vector<vector<int> >&grid,int row,int col,vector<vector<int> >&dp){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            
            if(i==0 && j==0){
                dp[i][j]=grid[i][j];
            }
            else{
                int up=1e9,left=1e9;

                if(i>0){
                    up=grid[i][j]+dp[i-1][j];
                }
                
                if(j>0){
                    left = grid[i][j]+dp[i][j-1];
                }
                
                dp[i][j]=min(up,left);
            }
        }
    }
    return dp[row-1][col-1];
     
}
int main()
{
    vector<vector<int>>grid={{1,3,1},{1,5,1},{4,2,1}};
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<int>>dp(row,vector<int>(col,-1));
    cout<<minPath(grid,row,col,dp);
 return 0;
}