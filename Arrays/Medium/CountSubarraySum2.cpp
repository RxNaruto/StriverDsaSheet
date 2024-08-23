#include<iostream>
#include<vector>
using namespace std;
int countSubarray(vector<int>arr,int k){
    int count =0;
    int size = arr.size();
    for(int i=0;i<size;i++){
        
        int sum = 0;
        for(int j=i;j<size;j++){
            sum+=arr[j];
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
    arr.push_back(2);
    arr.push_back(3);
    cout<<countSubarray(arr, 3);
 return 0;
}