#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution{
    private:
    bool bipartite(int start,int v,vector<int>adj[],vector<int>&color){
        queue<int>q;
        color[start]=0;
        q.push(start);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it: adj[node]){
                if(color[it]==-1){
                    color[it]=!color[node];
                    q.push(it);
                }
                else if(color[it]==color[node]){
                    return false;
                }
            }
            
        }
        return true;

    }
    public:
    bool checkBipartite(int v,vector<int>adj[]){
        vector<int>color(v,-1);
        for(int i=0;i<v;i++){
            if(color[i]==-1){
                if(bipartite(i,v,adj,color)==false)return false;
            }
        }
        return true;
    }
    
};
void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main()
{
   vector<int>adj[4];
	
	addEdge(adj, 0, 2);
   	addEdge(adj, 0, 3);
	addEdge(adj, 2, 3);
	addEdge(adj, 3, 1);

	Solution obj;
	bool ans = obj.checkBipartite(4,adj);    
	if(ans)cout << "1\n";
	else cout << "0\n";  

 return 0;
}