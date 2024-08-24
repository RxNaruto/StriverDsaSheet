#include<iostream>
#include<vector>
using namespace std;
int binarySearch(vector<int>arr,int k){
    int size = arr.size();
    int s=0,e=size-1;
    while(s<e){
        int mid = (s+e)/2;
        if(arr[mid]==k){
            return mid;
        }
        else if(arr[mid]>k){
            e=mid-1;
        }
        else{
            s=mid+1;
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
       arr.push_back(14);
        arr.push_back(15);
        cout<<binarySearch(arr,14);
 return 0;
}