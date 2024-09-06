#include <algorithm>
#include<iostream>
#include<vector>
using namespace std;
bool checkCows(vector<int>stalls,int dist,int cows){
    int cowsCnt = 1,last = stalls[0];
    int size = stalls.size();
    for(int i = 0;i<size;i++){
        if(stalls[i]-last>=dist){
            cowsCnt++;
            last = stalls[i];
        }
        
        
    }
    if(cowsCnt>=cows){
        return true;
    }
    return false;
}
int DistanceBwCows(vector<int>stalls,int cows){
    int size = stalls.size();
    int ans;
    sort(stalls.begin(),stalls.end());
    int low = 1;
    int high = stalls[size-1]-stalls[0];
    while(low<=high){
        int mid = (low+high)/2;
        if(checkCows(stalls,mid,cows)){
         
            low = mid+1;

        }
        else{
            high = mid-1;
        }

    }
    return high;


}
int main()
{
    vector<int>arr;
    arr.push_back(4);
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(6);
    
    int cows = 2;
    cout<<DistanceBwCows(arr,cows);
 return 0;
}