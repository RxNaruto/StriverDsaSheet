#include<iostream>
#include<vector>
using namespace std;

vector<int> twoSum(vector<int>& arr, int target) {
    int n = arr.size();
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if((arr[i] + arr[j]) == target) {
                cout << "Yes" << endl;
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

int main() {
    vector<int> arr = {2, 6, 5, 8, 11};
    vector<int> result = twoSum(arr, 5);

    if (result[0] == -1 && result[1] == -1) {
        cout << "No pair found with the given sum." << endl;
    } else {
        cout << "Pair found at indices: " << result[0] << " and " << result[1] << endl;
    }

    return 0;
}
