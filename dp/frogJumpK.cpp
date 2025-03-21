#include <climits>
#include<iostream>
#include<vector>
using namespace std;
int frogJump(int n,vector<int>&heights,int k){
    vector<int>dp(n,0);
    dp[0]=0;
    int jump;
    for(int i=1;i<n;i++){
        int minStep = INT_MAX;
        for(int j=1;j<=k;j++){
        if(i-j>=0){
            jump = dp[i-j]+abs(heights[i]-heights[i-j]);
            minStep=min(jump,minStep);
            }
           
        }
        dp[i]=minStep;
        
    }
    return dp[n-1];
}
int main()
{
    vector<int>heights={30,10,60,10,60,50};

    cout<<frogJump(6,heights,2);
 return 0;
}