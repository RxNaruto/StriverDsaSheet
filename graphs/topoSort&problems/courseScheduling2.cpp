#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> courseScheduling(int v, vector<vector<int>>& prereq) {
        vector<int> adj[v];
        for (auto it : prereq) {
            adj[it[1]].push_back(it[0]);
        }

        vector<int> indegree(v, 0);
        for (int i = 0; i < v; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        vector<int> topoSort;
        queue<int> q;
        for (int i = 0; i < v; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topoSort.push_back(node);
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        if (topoSort.size() == v) {
            return topoSort;
        }
        return {};
    }
};

int main() {
    int N = 4;

    vector<vector<int>> prerequisites = {
        {0, 1}, {1, 2}, {2, 3}
    };

    Solution obj;
    vector<int> ans = obj.courseScheduling(N, prerequisites);

    for (auto task : ans) {
        cout << task << " ";
    }
    cout << endl;

    return 0;
}
