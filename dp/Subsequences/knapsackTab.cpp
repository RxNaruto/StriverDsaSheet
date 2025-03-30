#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution{
    public:
    int knapsack(vector<int>&val,vector<int>&wt,int maxWt){
        vector<vector<int>>dp(val.size(),vector<int>(maxWt+1,0));
        for(int i=wt[0];i<=maxWt;i++){
            dp[0][i]=val[0];
        }
        for(int i=1;i<val.size();i++){
            for(int w=0;w<=maxWt;w++){
                int notPick = 0+dp[i-1][w];
                int pick = INT_MIN;
                if(wt[i]<=w){
                    pick =  val[i]+dp[i-1][w-wt[i]];
                }
                dp[i][w]=max(notPick,pick);
                
                
            }
        }
        return dp[val.size()-1][maxWt];
        
        

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