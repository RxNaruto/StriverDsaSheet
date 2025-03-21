#include <climits>
#include<iostream>
#include<vector>
using namespace std;
int frogJump(int n,vector<int>&heights){
    vector<int>dp(n,0);
    dp[0]=0;
    for(int i=1;i<n;i++){
        int fs=dp[i-1]+abs(heights[i]-heights[i-1]);
        int ss = INT_MAX;
        if(i>1){
            ss=dp[i-2]+abs(heights[i]-heights[i-2]);
        }
        dp[i]=min(fs,ss);

        
    }
    return dp[n-1];
}
int main()
{
    vector<int>heights={30,10,60,10,60,50};

    cout<<frogJump(6,heights);
 return 0;
}