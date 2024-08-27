#include<iostream>
#include<vector>
using namespace std;
int singleOccuring(vector<int>arr){
    int size = arr.size();
    if(size==1){
        return arr[0];
    }
    if(arr[0]!=arr[1])return arr[0];
    if(arr[size-1]!=arr[size-2])return arr[size-1];
    int low = 1,high = size-2;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]!=arr[mid+1] && arr[mid]!=arr[mid-1])return arr[mid];
        if(mid%2==1 && arr[mid]==arr[mid-1] || mid%2==0 && arr[mid]==arr[mid+1]){
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
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(6);
    cout<<singleOccuring(arr);
    
 return 0;
}