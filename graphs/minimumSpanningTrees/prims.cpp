#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int prims(int v,vector<vector<int> > adj[]){
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
        vector<int>vis(v,0);
        pq.push({0,0}); //{wt,node}
        int sum =0;
        while(!pq.empty()){
            auto it = pq.top();
            int node = it.second;
            int wt = it.first;
            pq.pop();
            if(vis[node]==1)continue;
            sum = sum+wt;
            vis[node]=1;
            for(auto it: adj[node]){
                int adjNode = it[0];
                if(!vis[adjNode]){
                    
                    pq.push({it[1],adjNode});
                }
            }

        }
        return sum;


    }
};
int main()
{
    int V = 5;
	vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
	vector<vector<int>> adj[V];
	for (auto it : edges) {
		vector<int> tmp(2);
		tmp[0] = it[1];
		tmp[1] = it[2];
		adj[it[0]].push_back(tmp);

		tmp[0] = it[0];
		tmp[1] = it[2];
		adj[it[1]].push_back(tmp);
	}

	Solution obj;
	int sum = obj.prims(V, adj);
	cout << "The sum of all the edge weights: " << sum << endl;
 return 0;
}