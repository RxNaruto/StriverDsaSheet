#include <bits/stdc++.h>
using namespace std;
class Solution {
    private:
    bool subSet(vector<int>&arr,int sum,int index){
        if(sum==0)return true;
        if(index==0){
            return (arr[index]==sum);
        }
        bool notTake = subSet(arr,sum,index-1);
        bool take = false;
        if(sum>=arr[index]){
            take = subSet(arr,sum-arr[index],index-1);
        }
        return notTake or take;
    }
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        return subSet(arr,sum,arr.size()-1);
        // code here
        
    }
};
