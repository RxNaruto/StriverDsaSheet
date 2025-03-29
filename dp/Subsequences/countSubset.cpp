#include<iostream>
#include<vector>
using namespace std;
int findSum(vector<int>&arr,int target,int index){
    if(target==0)return 1;
    if(index==0){
        if(arr[0]==target)return 1;
        return 0;
    }
    int notpick = findSum(arr,target,index-1);
    int pick = 0;
    if(arr[index]<=target){
        pick = findSum(arr,target-arr[index],index-1);
    }
    return pick+notpick;
}
int countSubset(vector<int>&arr,int target){
    return findSum(arr,target,arr.size()-1);
}
int main()
{
 return 0;
}