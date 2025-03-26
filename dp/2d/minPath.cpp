#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution {
    long long minPath(vector<vector<int>>& grid,int row,int col){
        if(row==0 && col==0){
            return grid[row][col];
        };
        if(row<0 || col<0)return INT_MAX;
        long long up = grid[row][col]+minPath(grid,row-1,col);
        long long left = grid[row][col]+minPath(grid,row,col-1);
        return min(up,left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        return minPath(grid,row-1,col-1);
        
    }
};
int main()
{
    vector<vector<int>>grid={{1,3,1},{1,5,1},{4,2,1}};
    Solution obj;
    cout<<obj.minPathSum(grid);
 return 0;
}