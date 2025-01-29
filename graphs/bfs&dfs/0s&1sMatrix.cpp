#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution{
    public:
    vector<vector<int> >zerosAndOnes(vector<vector<int>>grid){
        int n=grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        //{{x,y},steps}
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>dis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                       q.push({{i,j},0});
                       vis[i][j]=1;
                }
                else{
                    vis[i][j]=0;
                }
            }
        }
        int dRow[] = {-1,0,1,0};
        int dCol[] = {0,1,0,-1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            dis[row][col]=steps;
            for(int i =0;i<4;i++){
                int nRow = row+dRow[i];
                int nCol = col+dCol[i];
                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && !vis[nRow][nCol]){
                    vis[nRow][nCol]=1;
                    q.push({{nRow,nCol},steps+1});
                }
            }
        }
        return dis;


    }
};
int main()
{
   vector<vector<int>>grid{
        {0,1,1,0},
        {1,1,0,0},
        {0,0,1,1}
    };
	
	Solution obj;
	vector<vector<int>> ans = obj.zerosAndOnes(grid);
		
	for(auto i: ans){
		for(auto j: i)
			cout << j << " ";
		cout << "\n";
	}
	

}