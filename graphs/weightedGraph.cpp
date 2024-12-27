#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cout<<"Enter the value of n and m"<<endl;
    cin>>n>>m;
    int adj[n+1][m+1];
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u][v]=wt;
        adj[v][u]=wt;
    }

 return 0;
}