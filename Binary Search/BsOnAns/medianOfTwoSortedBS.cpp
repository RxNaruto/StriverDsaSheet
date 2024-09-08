#include<iostream>
#include<vector>
using namespace std;
double median(vector<int>arr1,vector<int>arr2){
    int s1 = arr1.size();
    int s2 = arr2.size();
    int t = (s1+s2);
    if(s1>s2)return median(arr2,arr1);
    int low = 0,high=s1;
    int left = (s1+s2+1)/2;
    while(low<=high){
        int mid1 = (low+high)/2;
        int mid2 = left-mid1;
        int l1= INT_MIN;
        int l2= INT_MIN;
        int r1= INT_MAX;
        int r2= INT_MAX;
        if(mid1<s1) r1 = arr1[mid1];
        if(mid2<s2) r2 = arr2[mid2];
        if(mid1-1>=0) l1 = arr1[mid1-1];
        if(mid2-1>=0) l2 = arr2[mid2-1];

        if(l1<=r2 && l2<=r1){
               if(t%2==1)return max(l1,l2);
               return (double)(max(l1,l2)+min(r1,r2))/2.0;
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
    arr1.push_back(4);
    arr1.push_back(6);
    arr2.push_back(1);
    arr2.push_back(3);
    arr2.push_back(5);
    cout<<median(arr1,arr2);
 return 0;
}