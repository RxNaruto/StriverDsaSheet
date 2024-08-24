#include<iostream>
#include<vector>
using namespace std;
int searchInsert(vector<int>arr,int x){
    int size = arr.size();
    int ans=size;
    int low = 0;
    int high = size -1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]>=x){
            ans = mid;
            high = mid -1;
        }
        else{
            low = mid+1;

        }
    }
    return ans;
}
int main()
{
    vector<int>arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(4);
    arr.push_back(7);
    cout<<searchInsert(arr,2);
 return 0;
}