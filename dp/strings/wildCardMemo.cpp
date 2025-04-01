class Solution {
    bool match(string s,string p,int i,int j,vector<vector<int>>&dp){
        if(i<0 && j<0)return true;
        if(i<0 && j>=0)return false;
        if(j<0 && i>=0){
            for(int ind=0;ind<=i;ind++){
                if(s[ind]!='*')return false;
            }
            return true;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if((s[i]==p[j]) || s[i]=='?' ) return dp[i][j]=match(s,p,i-1,j-1,dp);
        if(s[i]=='*'){
            return dp[i][j]= match(s,p,i-1,j,dp) || match(s,p,i,j-1,dp);
        }
        return dp[i][j]=false;
    }
public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return match(p,s,m-1,n-1,dp);
        
    }
};