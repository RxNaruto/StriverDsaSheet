#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int maxSum(vector<int>&arr){
    int prev1=arr[0];
    int prev2=0;
    for(int i=1;i<arr.size();i++){
        int take=arr[i];
        if(i>1)take+=prev2;
        int nonTake=0+prev1;
        int curr=max(take,nonTake);
        prev2=prev1;
        prev1=curr;
     
        
    }
    return prev1;
}
int main()
{
    vector<int>arr={1,8,3,4,5};
    cout<<maxSum(arr);

 return 0;
}