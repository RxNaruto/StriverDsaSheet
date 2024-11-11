#include<iostream>
#include<vector>
using namespace std;
int binaryGoal(vector<int>arr,int goal){
    if(goal<0)return 0;
    int size = arr.size();
    int l=0,r=0,sum=0,count=0;
    while(r<size){
        sum = sum + arr[r];

           while(sum>goal){
             sum = sum-arr[l];
            l++;
           }
        
        count = count+(r-l+1);
        r++;

    }
    return count;
}
int main()
{
    vector<int>arr;
    arr.push_back(1);
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(0);
    arr.push_back(1);
    int bg = binaryGoal(arr,2)-binaryGoal(arr,1);
    cout<<bg;
 return 0;
}