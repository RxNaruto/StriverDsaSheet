#include<iostream>
#include<vector>
using namespace std;
int rowWithMaxOnes(vector<vector<int>>arr){
    int maxn=INT_MIN;
    int row;
    int cnt;
    for (int i=0;i<arr.size();i++){
        cnt=0;
        for(int j=0;j<arr[i].size();j++){
            if(arr[i][j]==1){
                cnt++;
            }
            if(cnt>maxn){
                maxn=cnt;
                row=i;
            }


        }

    }
    if(maxn==0){
        return -1;
    }
    return row;
}
int main()
{
     vector<vector<int>>arr={{0,0},{0,0}};
     cout<<rowWithMaxOnes(arr);
     
 return 0;
}