#include<iostream>
#include<vector>
using namespace std;
int maxSum(vector<int>&arr,int index){
    if(index==0)return arr[index];
    if(index<0)return 0;
    int pick = arr[index]+maxSum(arr,index-2);
    int notPick = 0+maxSum(arr,index-1);
    return max(pick,notPick);
}
int main()
{
    vector<int>arr={1,2,3,4,5};
    cout<<maxSum(arr,4);
 return 0;
}