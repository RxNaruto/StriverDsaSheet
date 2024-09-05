#include<iostream>
#include<vector>
using namespace std;
int kthMissingNumber(vector<int>arr,int k){
    int size = arr.size();
    for(int i=0;i<size;i++){
        if(arr[i]<=k){
            k++;
        }
        else{
            break;
        }
    }
    return k;
}

int main()
{
    vector<int>arr;
    
    arr.push_back(4);
    arr.push_back(7);
    arr.push_back(9);
    arr.push_back(10);
    cout<<kthMissingNumber(arr,4);
 return 0;
}