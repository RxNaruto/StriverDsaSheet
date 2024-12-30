#include<iostream>
#include<vector>
using namespace std;
class Solution{
    private:
    bool dfs(int start,int parent,vector<int>&vis,vector<int>adj[]){
        vis[start]=1;
        for(auto adjacentNodes: adj[start]){
            if(!vis[adjacentNodes]){
                if(dfs(adjacentNodes,start,vis,adj))return true;

            }
            else if(adjacentNodes!=parent)return true;
        }
        return false;
    }
    public:
    bool detectCycle(int v,vector<int>adj[]){
        vector<int>vis(v+1,0);
        for(int i=1;i<=v;i++){
            if(!vis[i]){
                if(dfs(i,-1,vis,adj))return true;
            }
            

        }
        return false;
    }
};
int main()
{
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
    Solution obj;
    bool ans = obj.detectCycle(3, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";

 return 0;
}