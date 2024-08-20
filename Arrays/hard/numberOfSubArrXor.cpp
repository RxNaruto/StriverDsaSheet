#include<iostream>
#include<vector>
using namespace std;
int numberOfSubArr(vector<int>arr,int target){
    int size = arr.size();
    int count =0;
    for(int i=0;i<size-1;i++){
        int xorr=arr[i];
        if(xorr==target)count++;
        for(int j=i+1;j<size;j++){
            xorr = xorr ^ arr[j];
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
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(7);
    arr.push_back(8);
    arr.push_back(9);
    cout<<numberOfSubArr(arr,5);
 return 0;
}