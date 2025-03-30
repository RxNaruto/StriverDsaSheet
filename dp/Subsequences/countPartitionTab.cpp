//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countPartitions(vector<int>& arr, int d) {
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
        }
        if((sum-d)<0 || (sum-d)%2)return 0;
        int k=(sum-d)/2;
        vector<vector<int>>dp(arr.size(),vector<int>(k+1,0));
        if(arr[0]==0)dp[0][0]=2;
        else dp[0][0]=1;
        if(arr[0]!=0 && arr[0]<=d)dp[0][arr[0]]=1;
        for(int ind=1;ind<arr.size();ind++){
            for(int t=0;t<=k;t++){
                int notTake = dp[ind-1][t];
                int take = 0;
                if(arr[ind]<=t){
                    take = dp[ind-1][t-arr[ind]];
                }
                dp[ind][t]=take+notTake;
            }
            
        }
        return dp[arr.size()-1][k];
        
        // Code here
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countPartitions(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends