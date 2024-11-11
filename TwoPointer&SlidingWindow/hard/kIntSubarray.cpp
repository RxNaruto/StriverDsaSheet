#include<iostream>
#include<map>
#include<vector>
using namespace std;
int kSubarray(vector<int>arr,int k){
    int size = arr.size();
    int cnt = 0;
    for(int i=0;i<size;i++){
        map<int,int>mpp;
        for(int j=i;j<size;j++){
            mpp[arr[j]]++;
            if(mpp.size()>k){
                break;
            }
            if(mpp.size()==k){
                cnt = cnt+1;
            }
        }
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
    cout<<kSubarray(arr,3);
 return 0;
}