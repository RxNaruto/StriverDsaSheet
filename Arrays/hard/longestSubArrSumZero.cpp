#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
int longestSum(vector<int>arr){
    int size = arr.size();
    unordered_map<int,int >mpp;
    int maxi=0;
    int sum =0;
    for(int i=0;i<size;i++){
        sum+=arr[i];
        if(sum==0){
            maxi=i+1;
        }
        else if(mpp.find(sum)!=mpp.end()){
            maxi=max(maxi,i-mpp[sum]);
        }
        else{
            mpp[sum]=i;
        }
    }
    return maxi;

}
int main()
{
     vector<int>arr;
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(-5);
    arr.push_back(6);
    arr.push_back(2);
    
    cout<<longestSum(arr);
 return 0;
}