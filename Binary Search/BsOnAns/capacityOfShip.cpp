#include<iostream>
#include<vector>
using namespace std;
int checkDays(vector<int>weights,int cap){
    int days =1,load = 0;
    int size = weights.size();
    for(int i=0;i<size;i++){
        if(load+weights[i]>cap){
            days +=1;
            load = weights[i];
        }
        else{
            load+=weights[i];
        }
    }
    return days;
}
int capacity(vector<int>weights,int days){
    int size = weights.size();
    int sum = 0,max = INT_MIN;
    for(int i=0;i<size;i++){
        sum +=weights[i];
        if(weights[i]>max){
            max = weights[i];
        }
    }
    for(int i=max;i<=sum;i++){
        int daysReq = checkDays(weights,i);
        if(daysReq<=days){
            return i;
        }
    }
    return -1;
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