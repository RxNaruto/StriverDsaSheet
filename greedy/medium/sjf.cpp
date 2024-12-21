#include<iostream>
#include<vector>
using namespace std;
int sjf(vector<int>arr){
    sort(arr.begin(),arr.end());
    int t =0 , waitingTime =0;
    int size = arr.size();
    for(int i=0;i<size;i++){
        waitingTime+=t;
        t+=arr[i];
    }
    return waitingTime/size;
}
int main()
{
    vector<int>arr;
    arr.push_back(4);
    arr.push_back(3);
    arr.push_back(7);
    arr.push_back(1);
    arr.push_back(2);
    cout<<sjf(arr);
 return 0;
}