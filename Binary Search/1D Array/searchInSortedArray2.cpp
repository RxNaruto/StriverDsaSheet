#include<iostream>
#include<vector>
using namespace std;
bool searchInSortedArray(vector<int>arr,int target){
    int size = arr.size();
    int low = 0,high = size-1;
    while(low<=high){
        int mid = (low+high)/2;
        
        if(arr[mid]==target)return true;
        if(arr[low]==arr[mid] && arr[mid] == arr[high]){
            low = low+1;
            high = high-1;
            continue;
        }
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
    return false;

}
int main()
{
    vector<int>arr;
    arr.push_back(7);
    arr.push_back(8);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(3);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(6);
    cout<<searchInSortedArray(arr, 3);
 return 0;
}