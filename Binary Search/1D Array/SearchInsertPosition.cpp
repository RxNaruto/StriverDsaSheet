#include<iostream>
#include<vector>
using namespace std;
int searchInsertPosition(vector<int>arr,int x){
    int ans = arr.size();
    for(int i=0;i<arr.size();i++){
        if(arr[i]>=x){
            ans = i;
            break;
        }
    }
    return ans;
}
int main()
{
    vector<int>arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(4);
    arr.push_back(7);
    cout<<searchInsertPosition(arr,2);
 return 0;
}