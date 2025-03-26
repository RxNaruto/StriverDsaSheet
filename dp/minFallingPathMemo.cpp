#include<iostream>
#include<vector>
using namespace std;
class Solution {
    private:
    int minFall(vector<vector<int>>&matrix,int row,int col,vector<vector<int>>&dp){
        int size= matrix.size();
        if(col>=size || col<0)return 1e9;
        if(row==0)return matrix[0][col];
        if(dp[row][col]!=-1)return dp[row][col];
        int u=matrix[row][col]+minFall(matrix,row-1,col,dp);
        int ul=matrix[row][col]+minFall(matrix,row-1,col-1,dp);
        int ur=matrix[row][col]+minFall(matrix,row-1,col+1,dp);
        return dp[row][col]=min(u,min(ul,ur));
        
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int minE=INT_MAX;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            int ans = minFall(matrix,n-1,i,dp);
            minE=min(minE,ans);
        }
        return minE;
       
        
    }
};
int main()
{
 return 0;
}