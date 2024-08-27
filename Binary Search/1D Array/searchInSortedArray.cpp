#include<iostream>
#include<vector>
using namespace std;
int searchInSortedArray(vector<int>arr,int target){
    int size = arr.size();
    int low = 0,high = size-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]==target)return mid;
        else if(arr[low]<=arr[mid]){
            if(arr[low]<=target && arr[mid]>=target){
                high = mid-1;
            }
            else low = mid+1;
           
        }
        else{
            if(arr[mid]<=target && arr[high]>=target){
                low = mid+1;
            }
            else high = mid-1;
        }
    }
    return -1;

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
    cout<<searchInSortedArray(arr, 0);
 return 0;
}