#include <climits>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class Solution{
    public:
    int cheapestFlight(int n,vector<vector<int> >&flight,int src,int des,int stops){
        vector<pair<int,int> >adj[n];
        for(auto it: flight){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int> > >q;
        //{stops,{node,dist}}
        q.push({0,{src,0}});
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        while(!q.empty()){
            auto it = q.front();
            int stp = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            q.pop();

            if(stp>stops)continue;
            for(auto it: adj[node]){
                int adjNode = it.first;
                int edgeW = it.second;
                if(cost + edgeW < dist[adjNode] && stp<=stops){
                    dist[adjNode]=cost+ edgeW;
                    q.push({stp+1,{adjNode,dist[adjNode]}});
                }
            }
        }
        if(dist[des]==INT_MAX)return -1;
        return dist[des];


    }
};
int main()
{
    int n = 4, src = 0, dst = 3, K = 1;

    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600},
    {2, 3, 200}};

    Solution obj;

    int ans = obj.cheapestFlight(n, flights, src, dst, K);

    cout << ans;
    cout << endl;

 return 0;
}