#include<iostream>
#include<vector>
using namespace std;
bool smallestChecker(int sum,int i,int limit){
    if((sum/i)>=limit){
        return true;
    }
    return false;

}
int checkDivisor(vector<int>arr,int limit){
    int size = arr.size();
    int sum = 0;
    for(int i = 0;i<size;i++){
        sum += arr[i];
    }
    for(int i=1;i<size;i++){
        if(smallestChecker(sum,i,limit)){
            return i;
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
    int limit =8;
    cout<<checkDivisor(arr,limit);
 return 0;
}