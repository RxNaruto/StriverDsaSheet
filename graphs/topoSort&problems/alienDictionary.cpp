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
    public:
    string findOrder(string dict[],int N,int k){
        vector<int>adj[k];
        for(int i=0;i<N-1;i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            int minl = min(s1.length(),s2.length()); 
            for(int j=0;j<minl;j++){
                if(s1[j]!=s2[j]){
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }

            }
        }
        vector<int>topo = topoSort(k,adj);
        string ans =" ";
        for(auto it: topo){
            ans = ans + char(it+ 'a');
        }
        return ans;
    }

};
int main()
{
    int N = 5, K = 4;
	string dict[] = {"baa", "abcd", "abca", "cab", "cad"};
	Solution obj;
	string ans = obj.findOrder(dict, N, K);

	for (auto ch : ans)
		cout << ch << ' ';
	cout << endl;

 return 0;
}