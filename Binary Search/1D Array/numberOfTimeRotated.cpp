#include<iostream>
#include<vector>
using namespace std;
int nRotated(vector<int>arr){
    int size = arr.size();
    int low = 0;
    int high = size -1;
    int ans = INT_MAX;
    int index =-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[low]<=arr[mid]){
            if(ans>arr[low]){
                ans = arr[low];
                index = low;
            }
            low = mid+1;
        }
        else{
            if(ans>arr[mid]){
                ans = arr[mid];
                index = mid;
                high = mid-1;
            }
        }
    }
    return index;
}
int main()
{
    vector<int>arr;
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(7);
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    cout<<nRotated(arr);
 return 0;
}