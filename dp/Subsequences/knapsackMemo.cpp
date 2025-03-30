#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution{
    private:
    int maxVal(vector<int>&val,vector<int>&wt,int maxWt,int index,vector<vector<int>>&dp){
        if(index==0){
            if(maxWt>=wt[index])return val[0];
            else return 0;
        }
        if(dp[index][maxWt]!=-1)return dp[index][maxWt];
        int notPick = 0+ maxVal(val,wt,maxWt,index-1,dp);
        int pick = INT_MIN;
        if(wt[index]<=maxWt){
            pick = val[index]+maxVal(val,wt,maxWt-wt[index],index-1,dp);
        }
        return dp[index][maxWt]= max(pick,notPick);
    }
    public:
    int knapsack(vector<int>&val,vector<int>&wt,int maxWt){
        vector<vector<int>>dp(val.size(),vector<int>(maxWt+1,-1));
        return maxVal(val,wt,maxWt,val.size()-1,dp);

    }
};

int main()
{
    vector<int>val={30,40,50};
    vector<int>wt={3,2,5};
    Solution obj;
    int maxWt = 6;
    cout<<obj.knapsack(val,wt,maxWt);
 return 0;
}