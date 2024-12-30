#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution{
    private:
    bool detectCycle(int src,vector<int>&vis,vector<int>adj[]){
        vis[src]=1;
        queue<pair<int,int> >q;
        q.push({src,-1});
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto adjacentNode: adj[node]){
                if(!vis[adjacentNode]){
                    vis[adjacentNode]=1;
                    q.push({adjacentNode,node});
                }
                else if(parent!=adjacentNode){
                    return true;

                }


            }
            
        }
        return false;

    }

    public:
    bool findCycle(int v,vector<int>adj[]){
        vector<int>vis(v+1,0);
        for(int i=1;i<v;i++){
            if(!vis[i]){
                if(detectCycle(i,vis,adj))return true;
            }
        }
        return false;
        

    }
};
int main()
{
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
    Solution obj;
    cout<<obj.findCycle(4,adj);
 return 0;
}