class Solution {
    // int minDis(string &s1,string &s2,int i,int j,vector<vector<int>>&dp){
    //     if(i<0)return j+1;
    //     if(j<0)return i+1;
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     if(s1[i]==s2[j]){
    //         return 0+minDis(s1,s2,i-1,j-1,dp);
    //     }
    //     else{
    //         int ins = 1+minDis(s1,s2,i,j-1,dp); //insertion
    //         int del = 1+minDis(s1,s2,i-1,j,dp); //deletion
    //         int rep = 1+minDis(s1,s2,i-1,j-1,dp); //replace

    //         return min(ins,min(del,rep));
    //     }
    // }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<double>>dp(n+1,vector<double>(m+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=i;
        }
        for(int j=1;j<=m;j++){
            dp[0][j]=j;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=0 + dp[i-1][j-1];
                }
                else{
                    int ins = 1+dp[i][j-1]; //insertion
                    int del = 1+dp[i-1][j]; //deletion
                    int rep = 1+dp[i-1][j-1]; //replace
                    dp[i][j]=min(ins,min(del,rep));
                }
            }
        }
        return int(dp[n][m]);
        
    }
};