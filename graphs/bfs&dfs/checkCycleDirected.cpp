#include<iostream>
#include<vector>
using namespace std;
class Solution{
    private:
    bool dfs(int start,vector<int>adj[],vector<int>&vis,vector<int>&pathVis){
        vis[start]=1;
        pathVis[start]=1;
        for(auto it: adj[start]){
            if(!vis[it]){
                if(dfs(it,adj,vis,pathVis)==true)return true;
            }
            else if(pathVis[it]){
                return true;
            }
        }

        pathVis[start]=0;
        return false;
    }
    public:
    bool detectCycle(int v,vector<int>adj[]){
        vector<int>vis(v,0);
        vector<int>pathVis(v,0);
        for(int i=0;i<v;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathVis)==true)return true; 
            }
        }
        return false;
    }
};
int main()
{
    vector<int> adj[11] = {{}, {2}, {3}, {4, 7}, {5}, {6}, {}, {5}, {9}, {10}, {8}};
	int V = 11;
	Solution obj;
	bool ans = obj.detectCycle(V, adj);

	if (ans)
		cout << "True\n";
	else
		cout << "False\n";
 return 0;
}