#include<iostream>
#include<vector>
using namespace std;
double median(vector<int>arr1,vector<int>arr2,int m,int n,int k){
    
    
    if(m>n)return median(arr2,arr1,n,m,k);
    int low = max(k-n,0),high=min(k,m);
    int left = k;
    
    while(low<=high){
        int mid1 = (low+high)>>1;
        int mid2 = left-mid1;
        int l1= INT_MIN;
        int l2= INT_MIN;
        int r1= INT_MAX;
        int r2= INT_MAX;
        if(mid1<m) r1 = arr1[mid1];
        if(mid2<n) r2 = arr2[mid2];
        if(mid1-1>=0) l1 = arr1[mid1-1];
        if(mid2-1>=0) l2 = arr2[mid2-1];

        if(l1<=r2 && l2<=r1){
               return max(l1,l2);
        }
        else if(l1>r2)high = mid1-1;
        else low =mid1+1;
    }
    return 0;


}
int main()
{
    vector<int>arr1;
    vector<int>arr2;
    arr1.push_back(2);
    arr1.push_back(3);
    arr1.push_back(6);
    arr1.push_back(7);
    arr1.push_back(9);
    arr2.push_back(1);
    arr2.push_back(4);
    arr2.push_back(8);
    arr2.push_back(10);
    cout<<median(arr1,arr2,arr1.size(),arr2.size(),5);
 return 0;
}