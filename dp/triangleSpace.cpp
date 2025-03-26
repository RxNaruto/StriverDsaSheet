#include<iostream>
using namespace std;
class Solution {
    public:
        int minimumTotal(vector<vector<int> >& triangle) {
            int size = triangle.size();
            vector<int>front(size,0),cur(size,0);
            for(int i=0;i<size;i++){
                front[i]=triangle[size-1][i];
    
            }
            for(int i=size-2;i>=0;i--){
                for(int j=i;j>=0;j--){
                    int d=triangle[i][j]+front[j];
                    int dg=triangle[i][j]+front[j+1];
                    cur[j]=min(d,dg);
                }
                front = cur;
    
            }
            return front[0];
    
            
        }
};
int main()
{
 return 0;
}