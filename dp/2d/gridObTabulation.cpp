#include<iostream>
#include<vector>
using namespace std;
int uniquePaths(int row,int col,vector<vector<int> >&dp,vector<vector<int> >&grid){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            int up=0,left=0;
            if(grid[i][j]==-1)dp[i][j]=0;
            else if(i==0 && j==0)dp[i][j]=1;
            else{
               if(i>0)up=dp[i-1][j];
               if(j>0)left=dp[i][j-1];
               dp[i][j]=up+left;
            }
        }
    }
    return dp[row-1][col-1];



}
int main()
{ 
     int m=3;
     int n=3;
     vector<vector<int> >grid={{0,0,0},{0,-1,0},{0,0,0}};
     vector<vector<int>>dp(m,vector<int>(n,-1));
    cout<<uniquePaths(m,n,dp,grid);
 return 0;
}