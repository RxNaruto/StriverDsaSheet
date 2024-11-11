#include<iostream>
#include<vector>
using namespace std;
int binarySum(vector<int>arr,int k){
    int size = arr.size();
    int count =0;
    for(int i=0;i<size;i++){
        int sum = 0;
        for(int j=i;j<size;j++){
            sum = sum + arr[j];
            if(sum==k){
                count++;

            }
            
        }
    }
    return count;
}
int main()
{
    vector<int>arr;
    arr.push_back(1);
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(0);
    arr.push_back(1);
    cout<<binarySum(arr,2);
 return 0;
}