#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution{
    void dfs(int start,vector<int>adj[],vector<int>&vis,stack<int>&st){
        vis[start]=1;
        for(auto it: adj[start]){
            if(!vis[it]){
                dfs(it,adj,vis,st);
            }
        }
        st.push(start);

    }
    public:
    vector<int>topoSort(int v,vector<int>adj[]){
        vector<int>vis(v,0);
        stack<int>st;
        for(int i=0;i<v;i++){
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();

        }
        return ans;

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