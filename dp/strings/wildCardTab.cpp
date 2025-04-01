class Solution {
    // bool match(string s, string p,int i,int j,vector<vector<int>>&dp){
    //     if(i<0 && j<0)return true;
    //     if(i<0 && j>=0)return false;
    //     if(j<0 && i>=0){
    //         for(int ind=0;ind<=i;ind++){
    //             if(s[ind]!='*')return false;
    //         }
    //         return true;
    //     }
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     if((s[i]==p[j]) || s[i]=='?' ) return dp[i][j]=match(s,p,i-1,j-1,dp);
    //     if(s[i]=='*'){
    //         return dp[i][j]= match(s,p,i-1,j,dp) || match(s,p,i,j-1,dp);
    //     }
    //     return dp[i][j]=false;
    // }
public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        dp[0][0]=true;
         for (int j = 1; j <= m; j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 1];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if((s[i-1]==p[j-1]) || p[j-1]=='?'){
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*'){
                   dp[i][j]= dp[i][j-1] || 
                        dp[i-1][j];
                   }
                
            }
        }
        return dp[n][m];

        

        
        
    }
};