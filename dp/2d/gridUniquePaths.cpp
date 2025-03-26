#include<iostream>
#include<vector>
using namespace std;
int uniquePaths(vector<vector<int> >&grid,int row,int col){
    if(row==0 && col==0)return 1;
    if(row<0 || col<0)return 0;
    int up=uniquePaths(grid,row-1,col);
    int left=uniquePaths(grid,row,col-1);
    return up+left;
}
int main()
{
    vector<vector<int> >grid={{0,0,0},{0,0,0},{0,0,0}};
    cout<<uniquePaths(grid,2,2);
 return 0;
}