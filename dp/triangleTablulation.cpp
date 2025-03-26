#include<iostream>
using namespace std;
class Solution {
    public:
        int minimumTotal(vector<vector<int> >& triangle) {
            int size = triangle.size();
            vector<vector<int>>dp(size,vector<int>(size,-1));
            for(int i=0;i<size;i++){
                dp[size-1][i]=triangle[size-1][i];
    
            }
            for(int i=size-2;i>=0;i--){
                for(int j=i;j>=0;j--){
                    int d=triangle[i][j]+dp[i+1][j];
                    int dg=triangle[i][j]+dp[i+1][j+1];
                    dp[i][j]=min(d,dg);
                }
    
            }
            return dp[0][0];
    
            
        }
};
int main()
{
 return 0;
}