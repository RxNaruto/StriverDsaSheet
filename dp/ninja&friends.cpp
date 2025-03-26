#include<iostream>
using namespace std;
#include <bits/stdc++.h> 
int ninja(vector<vector<int>>&grid,int r,int ac,int bc){
    int gR = grid.size();
    int gC = grid[0].size();
    if(ac<0 || ac>gC-1 || bc<0 || bc>gC-1)return -1e8;
    if(r==gR-1){
        if(ac==bc)return grid[gR-1][ac];
        else{
            return grid[r][ac]+grid[r][bc];
        }
    };
    int maxi=-1e8;
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            if(ac==bc){
                maxi=max(grid[r][ac]+ninja(grid,r+1,ac+i,bc+j),maxi);
            }
            else{
                maxi=max(grid[r][ac]+grid[r][bc]+ninja(grid,r+1,ac+i,bc+j),maxi);
            }
        }
    }
    return maxi;
    
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    int size = grid.size();
    return ninja(grid,0,0,c-1);
    // Write your code here.
}
int main()
{
 return 0;
}