#include<iostream>
#include<vector>
using namespace std;
int maxOnes(vector<int>arr,int k){
    int size = arr.size();
    int l=0;
    int maxE = INT_MIN;
    int maxL = 0;
    int zeros = 0;
    for(int r=0;r<size;r++){
        if(arr[r]==0){
            zeros++;
        }
        if(zeros<=k){
            maxL = r-l+1;
            maxE = max(maxL,maxE);
        }
        else{
            while(zeros>k){
                if(arr[l]==0){
                    zeros = zeros-1;
                    
                }
                l++;
            }
        }
    }
    return maxE;
}
int main()
{
     vector<int>arr;
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(0);
    arr.push_back(0);
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(0);
    cout<<maxOnes(arr,2);
 return 0;
}