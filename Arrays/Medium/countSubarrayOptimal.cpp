#include<iostream>
#include<map>
using namespace std;
int countSubarrayOptimal(vector<int>arr,int k){
    int size = arr.size();
    map<int, int> mpp;
    mpp[0]=1;
    int preSum = 0,cnt =0;
    for(int i=0;i<size;i++){
        preSum+=arr[i];
        int remove = preSum-k;
        cnt+=mpp[remove];
        mpp[preSum]+=1;
    }
    return cnt;

}
int main()
{
     vector<int>arr;

    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    cout<<countSubarrayOptimal(arr, 3);
 return 0;
}