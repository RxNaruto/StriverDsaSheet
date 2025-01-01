#include <algorithm>
#include<iostream>
#include<vector>
using namespace std;
class Solution{
    private:
    bool dfs(int start,vector<int>adj[],vector<int>&vis,vector<int>&pathVis,vector<int>&checkVis){
             vis[start]=1;
             pathVis[start]=1;
             checkVis[start]=0;
             for(auto it: adj[start]){
                if(!vis[it]){
                    if(dfs(it,adj,vis,pathVis,checkVis)==true)
                    {
                        checkVis[it]=0;
                        return true;
                    }
                    
                }
                else if(pathVis[it]){
                    return true;
                }
             }
             checkVis[start]=1;
             pathVis[start]=0;
             return false;
     }
    public:
    vector<int>safeState(int v,vector<int>adj[]){
        vector<int>vis(v,0);
        vector<int>pathVis(v,0);
        vector<int>checkVis(v,0);
        vector<int>safeNodes;
        for(auto it:vis){
            if(!vis[it]){
                dfs(it,adj,vis,pathVis,checkVis);
            }
        }
        for(int i=0;i<v;i++){
            if(checkVis[i]==1)safeNodes.push_back(i);
        }
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