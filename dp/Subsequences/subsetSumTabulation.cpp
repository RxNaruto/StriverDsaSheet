#include <bits/stdc++.h> 
using namespace std;

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool>(k+1, false));

    // Base case: sum 0 is always achievable
    for (int i = 0; i < n; i++) {
        dp[i][0] = true;
    }

    // Base case: First element can form sum only if it's within range
    if (arr[0] <= k) {
        dp[0][arr[0]] = true;
    }

    // Filling the DP table
    for (int ind = 1; ind < n; ind++) {
        for (int target = 1; target <= k; target++) {  // Fixed loop condition
            bool notTake = dp[ind - 1][target];
            bool take = false;
            if (arr[ind] <= target) {
                take = dp[ind - 1][target - arr[ind]];
            }
            dp[ind][target] = take || notTake;
        }
    }

    return dp[n-1][k];  // Fixed return statement
}
