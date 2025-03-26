#include<iostream>
using namespace std;
class Solution {
    public:
        int minFallingPathSum(vector<vector<int> >& matrix) {
            int n=matrix.size();
            vector<vector<int> >dp(n,vector<int>(n,-1));
            for(int i=0;i<n;i++){
               dp[0][i]=matrix[0][i];
            }
            for(int i=1;i<n;i++){
                for(int j=0;j<n;j++){
                    int u=matrix[i][j]+dp[i-1][j];
                    int ul=matrix[i][j];
                    if(j>0){
                        ul+=dp[i-1][j-1];
                    }else{
                        ul=1e9;
                    }
                    int ur=matrix[i][j];
                    if(j<n-1){
                        ur+=dp[i-1][j+1];
                    }else{
                        ur=1e9;
                    }
                    dp[i][j]=min(u,min(ul,ur));
                    
                }
            }
            int minE=dp[n-1][0];
            for(int i=1;i<n;i++){
                minE=min(minE,dp[n-1][i]);
    
            }
            return minE;
           
            
        }
};

int main()
{
     return 0;
}