
class Solution {
    //performing shifting of index to the right
    // int longestSeq(string s1,string s2,int ind1,int ind2
    // ,vector<vector<int>>&dp){
    //     if(ind1==0 || ind2==0){
    //         return 0;
    //     }
    //     if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
    //     if(s1[ind1-1]==s2[ind2-1]){
    //         return dp[ind1][ind2]=1+longestSeq(s1,s2,ind1-1,ind2-1,dp);
    //     }
    //     return dp[ind1][ind2]=max(longestSeq(s1,s2,ind1-1,ind2,dp),longestSeq(s1,s2,ind1,ind2-1,dp));
    // }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n= text1.length();
        int m=text2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<=m;j++){
            dp[0][j]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};