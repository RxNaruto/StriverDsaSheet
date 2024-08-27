#include <climits>
#include<iostream>
#include<vector>
using namespace std;
int minimumRotated(vector<int>arr){
    int size = arr.size();
    int low = 0;
    int high = size-1;
    int ans = INT_MAX;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[low]<=arr[mid]){
            ans = min(ans,arr[low]);
            low = mid+1;
        }
        else{
            ans = min(ans,arr[mid]);
            high = mid-1;
        }
    }
    return ans;
}
int main()
{
    vector<int>arr;
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    
    arr.push_back(1);
    arr.push_back(2);
    
    cout<<minimumRotated(arr);
 return 0;
}