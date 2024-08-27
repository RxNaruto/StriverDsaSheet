#include<iostream>
#include<vector>
using namespace std;
int lastOccurance(vector<int>arr,int x){
    int size = arr.size();
    int low = 0;
    int high = size -1;
    int ans = -1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]==x){
            ans = mid;
            low = mid+1;

        }
        else if(arr[mid]>x){
            high = mid-1;
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
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(13);
    arr.push_back(13);
    arr.push_back(13);
    arr.push_back(20);
    arr.push_back(40);
    cout<<lastOccurance(arr,7);
 return 0;
}