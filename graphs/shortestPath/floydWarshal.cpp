#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
    void shortestDistance(vector<vector<int> > &grid){
        int size = grid.size();
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(grid[i][j]==-1){
                    grid[i][j]=1e9;
                }
                if(i==j){
                    grid[i][j]=0;
                }
            }
        }
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                for(int k=0;k<size;k++){
                    grid[i][j]=min(grid[i][j],(grid[i][k]+ grid[k][j]));

                }
            }

        }
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(grid[i][j]==1e9){
                    grid[i][j]=-1;
                }
                
            }
        }

        
    }
};
int main()
{
    int V = 4;
	vector<vector<int>> matrix(V, vector<int>(V, -1));
	matrix[0][1] = 2;
	matrix[1][0] = 1;
	matrix[1][2] = 3;
	matrix[3][0] = 3;
	matrix[3][1] = 5;
	matrix[3][2] = 4;

	Solution obj;
	obj.shortestDistance(matrix);
 
	for (auto row : matrix) {
		for (auto cell : row) {
			cout << cell << " ";
		}
		cout << endl;
	}
 return 0;
}