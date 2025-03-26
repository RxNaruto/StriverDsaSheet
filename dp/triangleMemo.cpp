#include<iostream>
#include<vector>
using namespace std;
class Solution{
    private:
    int minP(vector<vector<int> >&triangle,int n,int row,int col,vector<vector<int> >&dp){
        if(row==n-1)return triangle[n-1][col];
        if(dp[row][col]!=-1)return dp[row][col];
        int d=triangle[row][col]+minP(triangle,n,row+1,col,dp);
        int dg=triangle[row][col]+minP(triangle,n,row+1,col+1,dp);

        return dp[row][col]=min(d,dg);
    }
    public:
    int minPath(vector<vector<int> >&triangle,int n){
        vector<vector<int> >dp(n,vector<int>(n,-1));
        return minP(triangle,n,0,0,dp);

    }

    
};
int main()
{
 return 0;
}