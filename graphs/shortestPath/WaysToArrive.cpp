#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int countWays(int n,vector<vector<int> > &roads){
        vector<pair<int,int> >adj[n];
        for(auto it: roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});

            
        }
         priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
         //{dist,node}
          vector<int>dist(n,INT_MAX),ways(n,0);
          dist[0]=0;
          ways[0]=1;
          pq.push({0,0});
          while(!pq.empty()){
            auto it = pq.top();
            int dis = it.first;
            int node = it.second;
            pq.pop();

            for(auto it: adj[node]){
                int adjNode = it.first;
                int cost = it.second;

                if(dis + cost < dist[adjNode]){
                    dist[adjNode]=dis + cost;
                    ways[adjNode] = ways[node];
                    pq.push({dist[adjNode],adjNode});
                }
                else if(dis + cost == dist[adjNode]){
                    ways[adjNode]=ways[adjNode]+ways[node];

                }
            }

          }
          return ways[n-1];
    }
};
int main()
{
    int n = 7;

    vector<vector<int>> edges = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, 
    {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};

    Solution obj;

    int ans = obj.countWays(n, edges);

    cout << ans;
    cout << endl;
 return 0;
}