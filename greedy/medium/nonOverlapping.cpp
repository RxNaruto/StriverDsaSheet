#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Comparator function to sort intervals by end time
bool compare(vector<int> val1, vector<int> val2) {
    return val1[1] < val2[1];
}

int nonOverlap(vector<vector<int>> arr) {
    // Sort intervals by their end times
    sort(arr.begin(), arr.end(), compare);
    
    int cnt = 1;  // At least one interval can always be counted
    int lastEndTime = arr[0][1];

    // Iterate through the sorted intervals
    for (int i = 1; i < arr.size(); i++) {
        // Check if the current interval starts after or at the end of the last interval
        if (arr[i][0] >= lastEndTime) {
            cnt++;
            lastEndTime = arr[i][1];  // Update the last end time
        }
    }

    // The result is the number of intervals to remove to avoid overlaps
    return arr.size() - cnt;
}

int main() {
    vector<vector<int>> arr = {{1, 2}, {1, 2}, {1, 2}};
    cout << "Minimum intervals to remove for non-overlapping: " << nonOverlap(arr) << endl;

    return 0;
}
