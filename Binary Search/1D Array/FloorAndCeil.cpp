#include<iostream>
#include<vector>
using namespace std;
int Floor(vector<int>arr,int x){
    int size = arr.size();
    int low = 0;
    int high = size -1;
    int ans = size;
    while(low<=high){
        int mid= (low+high)/2;
        if(arr[mid]<=x){
            ans= arr[mid];
            low = mid+1;


        }
        else{
            high = mid-1;
        }

    }
    return ans;
}
int Ceil(vector<int>arr,int x){
    int size = arr.size();
    int low = 0;
    int high = size -1;
    int ans = size;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]>=x){
            ans = arr[mid];
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
    arr.push_back(4);
    arr.push_back(7);
    arr.push_back(8);
    arr.push_back(10);
    cout<<"Floor : "<<Floor(arr,8)<<endl;
    cout<<"Ceil : "<<Ceil(arr,8);
 return 0;
}