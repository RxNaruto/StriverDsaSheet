#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int xorSubarray(vector<int>arr,int target){
    int size = arr.size();
    int count=0;
    for(int i=0;i<size;i++){
        for(int j=i;j<size;j++){
            int xorr = 0;
            for(int k=i;k<=j;k++){
              xorr = xorr ^ arr[k];
             
            }
             if(xorr == target){
                count++;

              }
        }

    }
    return count;
}
int main()
{
    vector<int>arr;
    arr.push_back(4);
    arr.push_back(2);
    arr.push_back(2);
    arr.push_back(6);
    arr.push_back(4);
    cout<<xorSubarray(arr,6);
 return 0;
}