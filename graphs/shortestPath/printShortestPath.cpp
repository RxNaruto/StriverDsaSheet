#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n + 1, INT_MAX);
        dist[1] = 0;
        vector<int> parent(n + 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        pq.push({0, 1}); // Push {distance, node}

        while (!pq.empty()) {
            auto it = pq.top();
            int node = it.second;
            int dis = it.first;
            pq.pop();

            for (auto adjIt : adj[node]) {
                int adjNode = adjIt.first;
                int edgeDis = adjIt.second;
                if (dist[node] + edgeDis < dist[adjNode]) {
                    dist[adjNode] = dist[node] + edgeDis;
                    pq.push({dist[adjNode], adjNode});
                    parent[adjNode] = node;
                }
            }
        }

        if (dist[n] == INT_MAX) {
            return {-1}; // No path exists
        }

        vector<int> path;
        int node = n;
        while (parent[node] != node) {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        return path;
    }
};

int main() {
    int n = 5; // Number of nodes
    int m = 6; // Number of edges

    // Define the edges in the format {u, v, weight}
    vector<vector<int>> edges = {
        {1, 2, 2}, {1, 3, 4}, {2, 3, 1}, {2, 4, 7}, {3, 5, 3}, {4, 5, 1}
    };

    Solution obj;
    vector<int> result = obj.shortestPath(n, m, edges);

    // Output the result
    if (result[0] == -1) {
        cout << "No path exists from 1 to " << n << endl;
    } else {
        cout << "Shortest path from 1 to " << n << ": ";
        for (int node : result) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
