#include<iostream>
using namespace std;
class Solution {
    private:
    int minFall(vector<vector<int> >&matrix,int row,int col){
        int size= matrix.size();
        if(col>=size || col<0)return 1e9;
        if(row==0)return matrix[0][col];
        int u=matrix[row][col]+minFall(matrix,row-1,col);
        int ul=matrix[row][col]+minFall(matrix,row-1,col-1);
        int ur=matrix[row][col]+minFall(matrix,row-1,col+1);
        return min(u,min(ul,ur));
        
    }
public:
    int minFallingPathSum(vector<vector<int> >& matrix) {
        int n=matrix.size();
        int minE=INT_MAX;
        for(int i=0;i<n;i++){
            int ans = minFall(matrix,n-1,i);
            minE=min(minE,ans);
        }
        return minE;
       
        
    }
};

int main()
{
    vector<vector<int>>matrix={{2,1,3},{6,5,4},{7,8,9}};
    Solution obj;
    obj.minFallingPathSum(matrix);

 return 0;
}