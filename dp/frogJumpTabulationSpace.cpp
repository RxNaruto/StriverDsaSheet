#include <climits>
#include<iostream>
#include<vector>
using namespace std;
int frogJump(int n,vector<int>&heights){
    vector<int>dp(n,0);
    int prev1=0;
    int prev2=0;
    int curr;
    for(int i=1;i<n;i++){
        int fs=prev1+abs(heights[i]-heights[i-1]);
        int ss = INT_MAX;
        if(i>1){
            ss=prev2+abs(heights[i]-heights[i-2]);
        }

        curr=min(fs,ss);
        prev2=prev1;
        prev1=curr;

        
    }
    return prev1;
}
int main()
{
    vector<int>heights={30,10,60,10,60,50};

    cout<<frogJump(6,heights);
 return 0;
}