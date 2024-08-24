#include<iostream>
#include<vector>
using namespace std;
void swapFunction(vector<int>arr1,vector<int>arr2,int ind1,int ind2){
    swap(arr1[ind1],arr2[ind2]);
}
void mergeTwoSorted(vector<int>&arr1,vector<int>&arr2){
    int n = arr1.size();
    int m = arr2.size();
    int len = n+m;
    int gap = (len/2)+(len%2);
    while(gap>0){
        int left = 0;
        int right = left+gap;
        while(right< len){
            if(left<n && right>=m){
                swapFunction(arr1,arr2,left,right-n);


            }
            else if(left>=n){
                swapFunction(arr1,arr2,left-n,right-n);
            }
            else{
                swapFunction(arr1,arr2,left,right);
            }
            left++;
            right++;
        }
        if(gap==1)break;
        gap=(gap/2)+(gap%2);
        

    }
}
int main()
{
     vector<int>arr1 = {1,4,8,10};
    vector<int>arr2 = {2,3,9};
    mergeTwoSorted(arr1,arr2);
    for(int i=0;i<arr1.size();i++){
        cout<<arr1[i]<<" ";
    }
    for(int i=0;i<arr2.size();i++){
        cout<<arr2[i]<<" ";
    }
 return 0;
}