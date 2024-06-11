//XOR method
#include<iostream>
#include<vector>
using namespace std;
int numberApperingOnce(vector<int>&arr){
    int n=arr.size();
    int xorr=0;
    for(int i=0;i<n;i++){
        xorr=xorr ^ arr[i];

    }
    return xorr;

}
int main()
{
    vector<int> arr = {2, 2, 1};
    cout<<"The number appearing once in arr1 is "<<numberApperingOnce(arr)<<endl;
 return 0;
}