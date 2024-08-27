#include<iostream>
#include<vector>
using namespace std;
int countFirstOccurance(vector<int>arr,int x){
    int size = arr.size();
    int low =0,high = size -1;
    int ans = -1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]==x){
            ans = mid;
            high = mid -1;


        }
        else if(arr[mid]<x){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return ans;
}
int countLastOccurance(vector<int>arr,int x){
    int size = arr.size();
    int low = 0,high = size -1;
    int ans =-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]==x){
            ans = mid;
            low = mid+1;
        }
        else if(arr[mid]<x){
            low = mid+1;
            
        }
        else{
            high = mid-1;
        }

    }
    return ans;
}
int main()
{
    vector<int>arr;
    arr.push_back(2);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(3);
    arr.push_back(3);
    arr.push_back(3);
    arr.push_back(4);
    int first = countFirstOccurance(arr,3);
    int last = countLastOccurance(arr,3);
    cout<<"Number of Occurances : "<<last - first +1;
 return 0;
}