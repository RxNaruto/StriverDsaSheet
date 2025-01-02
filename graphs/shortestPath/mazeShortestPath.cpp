#include<iostream>
#include<queue>
#include<climits>
#include<vector>
using namespace std;
class Solution{
    public:
    int shortestPath(vector<vector<int> >&grid,pair<int,int>src,pair<int,int>dest){
        queue<pair<int,pair<int,int> > >q;  //{dist,{row,col}}
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int> >dist(n,vector<int>(m,INT_MAX));
        dist[src.first][src.second]=0;
        q.push({0,{src.first,src.second}});
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};

        while(!q.empty()){
            auto it= q.front();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            q.pop();

            for(int i=0;i<4;i++){
                int nrow = r+drow[i];
                int ncol = c+dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && dis+1<dist[nrow][ncol]){
                    if(nrow == dest.first && ncol == dest.second)return dis+1;
                    dist[nrow][ncol]=dis +1;
                    q.push({dis+1,{nrow,ncol}});
                }
            }

        }
        return -1;



    }
};
int main()
{
    pair<int, int> source, destination;
    source.first = 0;
    source.second = 1;
    destination.first = 2;
    destination.second = 2;

    vector<vector<int> > grid = {{1, 1, 1, 1},
                                {1, 1, 0, 1},
                                {1, 1, 1, 1},
                                {1, 1, 0, 0},
                                {1, 0, 0, 1}};

    Solution obj;

    int res = obj.shortestPath(grid, source, destination);

    cout << res;
    cout << endl;

    return 0;
 return 0;
}