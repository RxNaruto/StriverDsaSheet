class Solution {
    private:
    int minC(int i,int j,vector<int>&cuts,vector<vector<int>>&dp){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int mine = INT_MAX;
        for(int ind = i;ind<=j;ind++){
            int cost = cuts[j+1]-cuts[i-1]+
            minC(i,ind-1,cuts,dp)+minC(ind+1,j,cuts,dp);
             mine = min(mine,cost);
        }
        return dp[i][j]=mine;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
            int c = cuts.size();
            vector<vector<int>>dp(c+1,vector<int>(c+1,-1));
        return minC(1,c-2,cuts,dp);

        
    }
};