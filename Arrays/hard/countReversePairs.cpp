#include<iostream>
#include<vector>
using namespace std;
int countReversePairs(vector<int>arr){
    int size = arr.size();
    int count = 0;
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(arr[i]>arr[j]*2){
                count++;
            }
        }
    }
    return count;
}
int main()
{
    vector<int>arr;
  
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(4);
    cout<<countReversePairs(arr);
 return 0;
}