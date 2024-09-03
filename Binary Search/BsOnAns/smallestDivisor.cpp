#include <cmath>
#include<iostream>
#include<vector>
using namespace std;
int smallestDivisor(vector<int>arr,int target){
    int size = arr.size();
    int maxN = *max_element(arr.begin(),arr.end());
    for(int d=1;d<=maxN;d++){
        int sum = 0;
        for(int i=0;i<size;i++){
            sum += ceil((double)(arr[i]) / (double)(d));
        }
        if(sum<=target){
            return d;
        }

    }
    return -1;
}
int main()
{
    vector<int>arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    cout<<smallestDivisor(arr,8);
 return 0;
}