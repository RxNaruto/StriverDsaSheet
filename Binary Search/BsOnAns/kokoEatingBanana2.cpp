#include<iostream>
#include<vector>
using namespace std;
int findMax(vector<int>arr){
    int maxi = INT_MIN;
    for(int i = 0;i<arr.size();i++){
        maxi = max(maxi,arr[i]);
    }
    return maxi;
}
int countHourlyTime(vector<int>arr,int n){
    int totalTime = 0;
    int size = arr.size();
    for(int i =0;i<size;i++){
        totalTime+=ceil((double)arr[i]/(double)n);
    }
    return totalTime;
}
int kokoEatingBanana(vector<int>arr,int h){
    int maxi = findMax(arr);

    for(int i=1;i<=maxi;i++){
        int reqTime = countHourlyTime(arr,i);
        if(reqTime<=h)return i;
    }
    return maxi;
}
int main()
{
     vector<int>arr;
    arr.push_back(25);
    arr.push_back(12);
    arr.push_back(8);
    arr.push_back(14);
    arr.push_back(19);
    cout<<kokoEatingBanana(arr,5);
 return 0;
}