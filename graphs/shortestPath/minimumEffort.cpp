#include <climits>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class Solution{
    public:
    int MinimumEfforts(vector<vector<int> >& height){
        priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,
        greater<pair<int,pair<int,int> > > >pq;
        int n = height.size();
        int m = height[0].size();

        vector<vector<int> > dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;
        pq.push({0,{0,0}});
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1}; 
        while(!pq.empty()){
            auto it = pq.top();
            int diff = it.first;
            int r = it.second.first;
            int c = it.second.second;
            pq.pop();
            if(r==n-1 && c==m-1){
                return diff;
            }

            for(int i=0;i<4;i++){
                int nrow = r+drow[i];
                int ncol = c+dcol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int newEffort = max(abs(height[r][c]-height[nrow][ncol]),diff);
                    if(newEffort<dist[nrow][ncol]){
                        dist[nrow][ncol]=newEffort;
                        pq.push({newEffort,{nrow,ncol}});
                    }
                }
            }
          


        }
          return 0;
    }
};
int main()
{
    vector<vector<int>> heights = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};

    Solution obj;

    int ans = obj.MinimumEfforts(heights);

    cout << ans;
    cout << endl;
 return 0;
}