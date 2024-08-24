#include <algorithm>
#include<iostream>
#include<vector>
using namespace std;
int lowerBound(vector<int>arr,int k){
    int size = arr.size();
    for(int i=0;i<size;i++){
        if(arr[i]>=k){
            return i;
        }
    }
    return -1;

}
int main()
{
    vector<int>arr;
    arr.push_back(3);
    arr.push_back(5);
    arr.push_back(8);
    arr.push_back(15);
    arr.push_back(19);
    cout<<lowerBound(arr,9);
 return 0;
}