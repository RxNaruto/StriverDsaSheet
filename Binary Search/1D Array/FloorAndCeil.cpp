#include<iostream>
#include<vector>
using namespace std;
int floor(vector<int>arr,int x){
   int size = arr.size();
   int ans = -1;
   int low = 0;
   int high = size -1;
   while(low<=high){
    int mid = (low+high)/2;
    if(arr[mid]<=x){
        ans = arr[mid];
        low = mid+1;
    }
    else{
        high = mid-1;
    }
   }
   return ans;
}
int ceiling(vector<int>arr,int x){
    int size = arr.size();
    int ans = -1;
    int low = 0;
    int high = size-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>x){
            ans = mid;
            

        }
        else{
            high = mid -1;
        }
    }
} 
int main()
{
    vector<int>arr;
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(4);
    arr.push_back(7);
    arr.push_back(8);
    arr.push_back(10);
    cout<<floor(arr,8);
 return 0;
}