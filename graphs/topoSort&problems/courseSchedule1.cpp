#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution{
    public:
    bool isPossible(int v,vector<pair<int,int> >&prereq){
        vector<int>adj[v];
        for(auto it: prereq){
            adj[it.first].push_back(it.second);
        }
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
        if(topoSort.size()==v){
            return true;
        }
        return false;

        
    }
};
int main()
{
    vector<pair<int, int>> prerequisites;
	int N = 4;
	prerequisites.push_back({1, 0});
	prerequisites.push_back({2, 1});
	prerequisites.push_back({3, 2});

	Solution obj;
	bool ans = obj.isPossible(N, prerequisites);

	if (ans) cout << "YES";
	else cout << "NO";
	cout << endl;

 return 0;
}