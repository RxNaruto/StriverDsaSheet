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
        vector<int>prev(m+1,0),curr(m+1,0);
        
        for(int j=0;j<=m;j++){
            prev[j]=j;
        }
        for(int i=1;i<=n;i++){
            curr[0]=i;
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    curr[j]= 0+prev[j-1];
                }
                else{
                    
                   curr[j]=1+ min(curr[j-1],min(prev[j],prev[j-1]));
                }
                
            }
            prev = curr;
        }
        return prev[m];
        
    }
};