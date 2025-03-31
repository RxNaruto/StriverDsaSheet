//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
    
  public:
    int cutRod(vector<int> &price) {
        int size = price.size();
        int rl = size;
        vector<vector<int>>dp(size,vector<int>(size+1,0));
        for(int i=0;i<=rl;i++){
            dp[0][i]=price[0]*i;
        }
        for(int i=1;i<size;i++){
            for(int t=0;t<=rl;t++){
                int notTake = 0 + dp[i-1][t];
                int take = INT_MIN;
                int rodLen = i+1;
                if(rodLen<=t){
                    take = price[i]+dp[i][t-rodLen];
                }
                dp[i][t]=max(take,notTake);
            }
        }
        return dp[size-1][size];
        // code here
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;

        cout << ob.cutRod(a) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends