#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> res;
    int i = 0;

    // Add all intervals that end before the new interval starts
    while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
        res.push_back(intervals[i]);
        i++;
    }

    // Merge intervals that overlap with the new interval
    while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    
    // Add the merged interval
    res.push_back(newInterval);

    // Add the remaining intervals
    while (i < intervals.size()) {
        res.push_back(intervals[i]);
        i++;
    }

    return res;
}

int main() {
    vector<vector<int>> intervals = {{1, 3}, {6, 9}};
    vector<int> newInterval = {2, 5};

    // Call the insert function and get the result
    vector<vector<int>> result = insert(intervals, newInterval);

    // Display the result
    cout << "Resulting intervals after insertion: " << endl;
    for (const auto& interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}
