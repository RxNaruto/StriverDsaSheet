#include <algorithm>
#include<iostream>
#include <numeric>
#include<vector>
using namespace std;
int checkDays(vector<int>weights,int cap){
    int load = 0,days = 1;
    int size = weights.size();
    for(int i=0;i<size;i++){
        if(load+weights[i]>cap){
            days+=1;
            load = weights[i];

        }
        else{
            load+=weights[i];
        }
    }
    return days;
}
int capacity(vector<int>weight,int days){
    int high = accumulate(weight.begin(),weight.end(),0);
    int low = *max_element(weight.begin(),weight.end());
    while(low<=high){
        int mid = (low+high)/2;
        
        if(checkDays(weight,mid)<=days){
            high= mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return low;
    
}
int main()
{
    vector<int>weights;
    weights.push_back(5);
    weights.push_back(4);
    weights.push_back(5);
    weights.push_back(2);
    weights.push_back(3);
    weights.push_back(4);
    weights.push_back(5);
    weights.push_back(6);
    int days =5;
    cout<< capacity(weights,days);
 return 0;
}