#include<iostream>
#include<vector>
using namespace std;
class Solution{
    private:
    void dfs(int row,int col,vector<vector<int> >&ans,vector<vector<int> >&img,int newColor,int delRow[],int delCol[],int iniColor){
        ans[row][col]=newColor;
        int n = img.size();
        int m = img[0].size();
        for(int i=0;i<4;i++){
            int nrow = row+delRow[i];
            int ncol = col+delCol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && img[nrow][ncol]==iniColor && ans[nrow][ncol]!=newColor){
                dfs(nrow,ncol,ans,img,newColor,delRow,delCol,iniColor);
            }
        }


    }
    public:
    vector<vector<int> >floodFil(int sr,int sc,int newColor,vector<vector<int> >&img){
            vector<vector<int> >ans = img;
            int iniColor = img[sr][sc];
            int delRow[] = {-1,0,1,0};
            int delCol[] = {0,1,0,-1};
            dfs(sr,sc,ans,img,newColor,delRow,delCol,iniColor);
            return ans;
 

    }
};
int main()
{
    vector<vector<int> >image{
	    {1,1,1},
	    {1,1,0},
	    {1,0,1}
	};
    int sr=1,sc=1,newColor=2;
    Solution obj;
	vector<vector<int> > ans = obj.floodFil(1, 1, 2,image);
	for(auto i: ans){
		for(auto j: i)
			cout << j << " ";
		cout << "\n";
	}
 return 0;
}