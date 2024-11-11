#include<iostream>
#include<map>
#include<vector>
using namespace std;
int kSubarray(vector<int>arr,int k){
    int size =arr.size();
    int l=0,r=0,cnt=0;
    map<int,int>mpp;
    while(r<size){
        mpp[arr[r]]++;
        while(mpp.size()>k){
            mpp[arr[l]]--;
            if(mpp[arr[l]]==0)mpp.erase(arr[l]);
            l++;
        }
        if(mpp.size()<=k){
            cnt = cnt+(r-l+1);
        }
        r++;

    }
    return cnt;
}
int main()
{
    vector<int>arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(4);
    cout<<kSubarray(arr,3)-kSubarray(arr,2);
 return 0;
}