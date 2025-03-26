#include<iostream>
#include<vector>
using namespace std;
class Solution{
    private:
    int minP(vector<vector<int> >&triangle,int n,int row,int col){
        if(row==n-1)return triangle[n-1][col];
        int d=triangle[row][col]+minP(triangle,n,row+1,col);
        int dg=triangle[row][col]+minP(triangle,n,row+1,col+1);

        return min(d,dg);
    }
    public:
    int minPath(vector<vector<int> >&triangle,int n){
        return minP(triangle,n,0,0);

    }

    
};
int main()
{
 return 0;
}