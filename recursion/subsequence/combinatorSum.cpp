#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void findCombinator(int ind, int target, vector<int>& ds, vector<vector<int>>& ans, vector<int>& arr) {
        if (ind == arr.size()) {
            if (target == 0) {
                ans.push_back(ds);
            }
            return;
        }
        if (arr[ind] <= target) {
            ds.push_back(arr[ind]);
            findCombinator(ind, target - arr[ind], ds, ans, arr);
            ds.pop_back();
        }
        findCombinator(ind + 1, target, ds, ans, arr);
    }
};

int main() {
    Solution obj;
    vector<int> v{2, 3, 6, 7};
    int target = 7;
    vector<int> ds;
    vector<vector<int>> ans;  // Declare ans before passing it
    
    obj.findCombinator(0, target, ds, ans, v); // Correct function call

    cout << "Combinations are: " << endl;
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    
    return 0;
}
