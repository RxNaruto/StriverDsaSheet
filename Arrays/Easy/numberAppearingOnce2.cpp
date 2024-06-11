#include<iostream>
#include<vector>
using namespace std;

int numberAppearingOnce(vector<int> &arr){
    int n=arr.size();
    int max=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    vector<int>arr2(max+1,0);
    for(int i=0;i<n;i++){
        arr2[arr[i]]++;

    }
    for(int i=0;i<=max;i++){
        if(arr2[i]==1){
            return i;
        }
    }
    return -1;
}
int main()
{
    vector<int> arr = {2, 2, 1};

    
    cout<<"The number appearing once in arr1 is "<<numberAppearingOnce(arr)<<endl;
  
 return 0;
}