#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution{
    public:
    vector<int>bellmanFord(int v,vector<vector<int> > &edges,int src){
        vector<int>dist(v,INT_MAX);
        dist[src]=0;
        for(int i=0;i<=v-1;i++){
            for(auto it: edges){
                int u = it[0];
                int v = it[1];
                int wt = it[2];

                if(dist[u]!= INT_MAX && dist[u]+wt < dist[v]){
                    dist[v]=dist[u]+wt;
                }
            }


        }
        //to check for negative edge cycle if it reduces then -ve edges present
        //otherwise it can't reduce more than n-1 iteration
        for(auto it: edges){
                int u = it[0];
                int v = it[1];
                int wt = it[2];

                if(dist[u]!= INT_MAX && dist[u]+wt < dist[v]){
                    return {-1};
                }
        }
        return dist;
    }
};
int main()
{
    int V = 6;
	vector<vector<int>> edges(7, vector<int>(3));
	edges[0] = {3, 2, 6};
	edges[1] = {5, 3, 1};
	edges[2] = {0, 1, 5};
	edges[3] = {1, 5, -3};
	edges[4] = {1, 2, -2};
	edges[5] = {3, 4, -2};
	edges[6] = {2, 4, 3};

	int S = 0;
	Solution obj;
	vector<int> dist = obj.bellmanFord(V, edges, S);
	for (auto d : dist) {
		cout << d << " ";
	}
	cout << endl;
 return 0;
}