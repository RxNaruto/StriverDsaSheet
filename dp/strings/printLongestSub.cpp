//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
    
  public:
    vector<char> all_longest_common_subsequences(string s, string t) {
       int n= s.length();
        int m=t.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<=m;j++){
            dp[0][j]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int len = dp[n][m];
        vector<char>ans(len,'$');
        int index = len-1;
        int i=n,j=m;
        while(i>0 && j>0){
            if(s[i-1]==t[j-1]){
                ans[index]=s[i-1];
                index--;
                i--,j--;
                
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
        return ans;
     
    }
};



//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        vector<char> ans = ob.all_longest_common_subsequences(s, t);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends