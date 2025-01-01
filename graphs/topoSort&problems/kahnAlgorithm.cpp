#include<iostream>
#include<queue>
#include <type_traits>
#include<vector>
using namespace std;
class Solution{
    public:
    vector<int>topoSort(int v,vector<int>adj[]){
        vector<int>indegree(v,0);
        for(int i=0;i<v;i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        vector<int>topoSort;
        queue<int>q;
        for(int i=0;i<v;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topoSort.push_back(node);
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0){q.push(it);};
            }
        }
        return topoSort;
    }
};
int main()
{
    vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
	int V = 6;
	Solution obj;
	vector<int> ans = obj.topoSort(V, adj);

	for (auto node : ans) {
		cout << node << " ";
	}
	cout << endl;

 return 0;
}