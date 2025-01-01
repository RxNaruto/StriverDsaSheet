#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
    public:
    vector<int>safeState(int v,vector<int>adj[]){
        vector<int>revAdj[v];
        vector<int>indegree(v,0);
        for(int i=0;i<v;i++){
            for(auto it: adj[i]){
                revAdj[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int>q;
        vector<int>safeNodes;
        for(int i=0;i<v;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            for(auto it: revAdj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        sort(safeNodes.begin(),safeNodes.end());
        return safeNodes;
    }
};
int main()
{
    vector<int> adj[12] = {{1}, {2}, {3, 4}, {4, 5}, {6}, {6}, {7}, {}, {1, 9}, {10},
		{8}, {9}
	};
	int V = 12;
	Solution obj;
	vector<int> safeNodes = obj.safeState(V, adj);

	for (auto node : safeNodes) {
		cout << node << " ";
	}
	cout << endl;
 return 0;
}