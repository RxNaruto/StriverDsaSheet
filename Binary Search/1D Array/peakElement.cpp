#include<iostream>
#include<vector>
using namespace std;
int peakElement(vector<int>arr){
    int size = arr.size();
    if(size==1){
        return 0;
    }
    if(arr[0]>arr[1]){
        return 0;
    }
    if(arr[size-1]>arr[size-2]){
        return size-1;
    }
    int low = 1;
    int high = size-2;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1])return mid;
        else if(arr[mid]>arr[mid-1]){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return -1;


}
int main()
{
    vector<int>arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(7);
    arr.push_back(8);
    arr.push_back(5);
    arr.push_back(1);
    cout<<peakElement(arr);
 return 0;
}