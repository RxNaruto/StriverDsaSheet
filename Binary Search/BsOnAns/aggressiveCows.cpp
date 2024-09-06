#include <algorithm>
#include<iostream>
#include<vector>
using namespace std;
bool checkCows(vector<int>arr,int dist,int cows){
    int cowCnt = 1,last = arr[0];
    int size = arr.size();
    for(int i =0;i<size;i++){
        if(arr[i]-last>=dist){
            cowCnt++;
            last = arr[i];
        }
    }
    if(cowCnt>=cows){
        return true;
    }
    return false;
}
int DistanceBwCows(vector<int>arr,int cows){
    int size = arr.size();
    sort(arr.begin(),arr.end());
    int min = *min_element(arr.begin(),arr.end());
    int max = *max_element(arr.begin(),arr.end());
    for(int i=min;i<=max;i++){
        if(checkCows(arr,i,cows)==true){
            continue;

        }
        else{
            return i-1;
        }
    }
    return -1;
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