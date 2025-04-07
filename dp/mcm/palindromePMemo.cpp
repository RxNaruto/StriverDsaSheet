class Solution {
    private:
    bool isPalindrome(int i,int j,string s){
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    int minC(string &s,int i,int n,vector<int>&dp){
        if(i==n)return 0;
        if(dp[i]!=-1)return dp[i];
        int minCost=INT_MAX;
        for(int j=i;j<n;j++){
            if(isPalindrome(i,j,s)){
                int cost=1+minC(s,j+1,n,dp);
                minCost = min(minCost,cost);
            }
        }
        return dp[i]=minCost;
    }
public:
    int minCut(string s) {
        vector<int>dp(s.size(),-1);
        return minC(s,0,s.size(),dp)-1;
        
    }
};