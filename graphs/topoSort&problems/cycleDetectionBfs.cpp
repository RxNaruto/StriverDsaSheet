#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution{
    private:
    vector<int>topoSort(int v,vector<int>adj[]){
        vector<int>indegree(v,0);
        for(int i=0;i<v;i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        vector<int>topo;
        queue<int>q;
        for (int i = 0; i < v; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        return topo;
    }
    public:
    bool checkCycle(int v,vector<int>adj[]){
        vector<int>ans = topoSort(v,adj);
        if(ans.size()==v){
            return false;
        }
        return true;

    }
};
int main()
{
    vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
	int V = 6;
	Solution obj;
	cout<<obj.checkCycle(V, adj);
 return 0;
}