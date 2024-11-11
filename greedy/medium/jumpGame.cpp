#include<iostream>
#include<vector>
using namespace std;
bool jumpGame(vector<int>arr){
    int size = arr.size();
    int maxInd = 0;
    for(int i=0;i<size;i++){
        if(i>maxInd)return false;
        maxInd = max(maxInd,i+arr[i]);
    }
    return true;
}
int main()
{
    vector<int>arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(4);
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(0);
    arr.push_back(2);
    arr.push_back(5);

    cout<<jumpGame(arr);
    
 return 0;
}