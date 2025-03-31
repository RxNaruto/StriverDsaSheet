//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
   
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        vector<vector<int>>dp(val.size(),vector<int>(capacity+1,0));
        for(int i=0;i<=capacity;i++){
            dp[0][i]=(i/wt[0])*val[0];
        }
        for(int i=1;i<val.size();i++){
            for(int t=0;t<=capacity;t++){
                int notTake = 0+dp[i-1][t];
                int take = INT_MIN;
                if(wt[i]<=t){
                    take = val[i]+dp[i][t-wt[i]];
                }
                dp[i][t]=max(take,notTake);
            }
        }
        return dp[val.size()-1][capacity];
        // code here
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int W;
        cin >> W;
        cin.ignore();
        string str;
        getline(cin, str);
        stringstream ss(str);
        vector<int> val;
        int num;
        while (ss >> num) {
            val.push_back(num);
        }
        string str2;
        getline(cin, str2);
        stringstream ss2(str2);
        vector<int> wt;
        int num2;
        while (ss2 >> num2) {
            wt.push_back(num2);
        }
        Solution ob;
        cout << ob.knapSack(val, wt, W) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends