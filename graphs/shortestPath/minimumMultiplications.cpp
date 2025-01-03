#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int minimumMultiplications(vector<int>adj,int src,int end){
        queue<pair<int,int> >q;
          vector<int>dist(100000,INT_MAX);
          dist[src]=0;
          q.push({src,0});
          while(!q.empty()){
            int node = q.front().first;
            int step = q.front().second;
            q.pop();
            for(auto it: adj){
                int nNode = (it* node)%100000;
                if(step+1 < dist[nNode]){
                    dist[nNode]=step+1;
                    if(nNode == end){
                        return dist[nNode];
                    }
                    q.push({nNode,step+1});
                }

            }

          }
          return -1;


    }
};
int main()
{
    vector<int> adj;
    adj.push_back(3);
    adj.push_back(4);
    adj.push_back(65);
    int start = 7;
    int end = 66175;
    Solution sol;
    cout<<sol.minimumMultiplications(adj,start,end);
 return 0;
}